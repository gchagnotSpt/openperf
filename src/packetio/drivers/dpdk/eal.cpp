#include <cerrno>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include <net/if.h>
#include <sys/capability.h>

#include "lwip/netif.h"
#include "tl/expected.hpp"

#include "core/icp_core.h"
#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/drivers/dpdk/eal.h"
#include "packetio/drivers/dpdk/queue_utils.h"
#include "packetio/drivers/dpdk/worker_api.h"
#include "packetio/drivers/dpdk/model/physical_port.h"
#include "packetio/generic_port.h"

namespace icp {
namespace packetio {
namespace dpdk {

struct named_cap_flag {
    const char *name;
    int flag;
};

static struct named_cap_flag cap_permissions[] = {
    { "cap_ipc_lock", CAP_IPC_LOCK },
    { "cap_net_raw",  CAP_NET_RAW  },
};

static bool sufficient_permissions()
{
    cap_t caps = cap_get_proc();
    if (!caps) {
        ICP_LOG(ICP_LOG_ERROR, "Could not retrieve any capabilities.\n");
        return (false);
    }

    bool have_permissions = true;  /* assume we have permission unless we don't */
    for(auto &item : cap_permissions) {
        cap_flag_value_t flag;
        if (cap_get_flag(caps, item.flag, CAP_EFFECTIVE, &flag) == -1) {
            ICP_LOG(ICP_LOG_ERROR, "cap_get_flag returned error for %s.\n", item.name);
            have_permissions = false;
            break;
        } else if (!flag) {
            ICP_LOG(ICP_LOG_INFO, "Missing required DPDK capability: %s\n", item.name);
            have_permissions = false;
        }
    }

    cap_free(caps);

    return (have_permissions);
}

static void log_port(uint16_t port_idx, model::port_info& info)
{
    struct ether_addr mac_addr;
    rte_eth_macaddr_get(port_idx, &mac_addr);

    if (auto if_index = info.if_index(); if_index > 0) {
        char if_name[IF_NAMESIZE];
        if_indextoname(if_index, if_name);
        ICP_LOG(ICP_LOG_INFO, "  dpdk%d: %02x:%02x:%02x:%02x:%02x:%02x (%s) attached to %s\n",
                port_idx,
                mac_addr.addr_bytes[0],
                mac_addr.addr_bytes[1],
                mac_addr.addr_bytes[2],
                mac_addr.addr_bytes[3],
                mac_addr.addr_bytes[4],
                mac_addr.addr_bytes[5],
                info.driver_name(), if_name);
    } else {
        ICP_LOG(ICP_LOG_INFO, "  dpdk%d: %02x:%02x:%02x:%02x:%02x:%02x (%s)\n",
                port_idx,
                mac_addr.addr_bytes[0],
                mac_addr.addr_bytes[1],
                mac_addr.addr_bytes[2],
                mac_addr.addr_bytes[3],
                mac_addr.addr_bytes[4],
                mac_addr.addr_bytes[5],
                info.driver_name());
    }
}

static int log_link_status_change(uint16_t port_id,
                                  rte_eth_event_type event __attribute__((unused)),
                                  void *cb_arg __attribute__((unused)),
                                  void *ret_param __attribute__((unused)))
{
    assert(event == RTE_ETH_EVENT_INTR_LSC);
    struct rte_eth_link link;
    rte_eth_link_get_nowait(port_id, &link);
    if (link.link_status == ETH_LINK_UP) {
        ICP_LOG(ICP_LOG_INFO, "Port %u Link Up - speed %u Mbps - %s-duplex\n",
                port_id, link.link_speed,
                link.link_duplex == ETH_LINK_FULL_DUPLEX ? "full" : "half");
    } else {
        ICP_LOG(ICP_LOG_INFO, "Port %u Link Down\n", port_id);
    }

    return (0);
}

__attribute__((const))
static const char* dpdk_logtype(int logtype)
{
    /* Current as of DPDK release 18.08 */
    static const char* logtype_strings[] = {
        "lib.eal",
        "lib.malloc",
        "lib.ring",
        "lib.mempool",
        "lib.timer",
        "pmd",
        "lib.hash",
        "lib.lpm",
        "lib.kni",
        "lib.acl",
        "lib.power",
        "lib.meter",
        "lib.sched",
        "lib.port",
        "lib.table",
        "lib.pipeline",
        "lib.mbuf",
        "lib.cryptodev",
        "lib.efd",
        "lib.eventdev",
        "lib.gso"
        "reserved1",
        "reserved2",
        "reserved3",
        "user1",
        "user2",
        "user3",
        "user4",
        "user5",
        "user6",
        "user7",
        "user8"
    };

    return ((logtype >= 0 && logtype < static_cast<int>(icp_count_of(logtype_strings)))
            ? logtype_strings[logtype]
            : "unknown");
}

__attribute__((const))
static enum icp_log_level dpdk_loglevel(int loglevel)
{
    /*
     * This should be kept in sync with the inferred log levels found in the
     * argument parser.
     */
    switch (loglevel) {
    case RTE_LOG_EMERG:
        return ICP_LOG_CRITICAL;
    case RTE_LOG_ALERT:
        return ICP_LOG_ERROR;
    case RTE_LOG_CRIT:
        return ICP_LOG_WARNING;
    case RTE_LOG_ERR:
        return ICP_LOG_INFO;
    case RTE_LOG_WARNING:
    case RTE_LOG_NOTICE:
    case RTE_LOG_INFO:
        return ICP_LOG_DEBUG;
    case RTE_LOG_DEBUG:
        return ICP_LOG_TRACE;
    default:
        return ICP_LOG_NONE;
    }
}

static ssize_t eal_log_write(void* cookie __attribute__((unused)),
                             const char* buf, size_t size)
{
    /*
     * The manpage says size == 0 is an error (by corollary) but dare
     * we not check?
     */
    if (size == 0) return (0);

    /*
     * icp_log needs all of the messages to be terminated with a new-line, so fix up
     * any messages that lack such niceties.
     */
    const char *format = (buf[size-1] == '\n') ? "%.*s" : "%.*s\n";

    /*
     * We can't grab the right function with a macro, so call the
     * actual function and provide the logtype instead.
     */
    icp_log(dpdk_loglevel(rte_log_cur_msg_loglevel()),
            dpdk_logtype(rte_log_cur_msg_logtype()),
            format, static_cast<int>(size), buf);

    return (size);
}

static __attribute__((const)) int eal_workers()
{
    int count = 0;
    unsigned i = 0;
    RTE_LCORE_FOREACH_SLAVE(i) {
        if (rte_lcore_is_enabled(i)) {
            count++;
        }
    }
    return (count);
}

struct queue_count {
    uint16_t rx;
    uint16_t tx;
};

static std::map<int, queue_count> get_port_queue_counts(const std::vector<queue::descriptor>& descriptors)
{
    std::map<int, queue_count> port_queue_counts;

    for (auto& d : descriptors) {
        if (port_queue_counts.find(d.port_id) == port_queue_counts.end()) {
            port_queue_counts.emplace(d.port_id, queue_count());
        }

        auto& queue_count = port_queue_counts[d.port_id];

        switch (d.mode) {
        case queue::queue_mode::RX:
            queue_count.rx++;
            break;
        case queue::queue_mode::TX:
            queue_count.tx++;
            break;
        case queue::queue_mode::RXTX:
            queue_count.tx++;
            queue_count.rx++;
            break;
        default:
            break;
        }
    }

    return (port_queue_counts);
}

static void configure_all_ports(const std::map<int, queue_count>& port_queue_counts,
                                rte_mempool* rx_mempool)
{
    uint16_t port_id = 0;
    RTE_ETH_FOREACH_DEV(port_id) {
        auto port = model::physical_port(port_id, rx_mempool);
        auto result = port.low_level_config(port_queue_counts.at(port_id).rx,
                                            port_queue_counts.at(port_id).tx);
        if (!result) {
            throw std::runtime_error(result.error());
        }
    }
}

static int get_waiting_lcore()
{
    int i = 0;
    RTE_LCORE_FOREACH_SLAVE(i) {
        switch (rte_eal_get_lcore_state(i)) {
        case FINISHED:
            rte_eal_wait_lcore(i);
            break;
        case WAIT:
            return (i);
        default:
            continue;
        }
    }

    return (-1);
}

eal::eal(void* context, std::vector<std::string> args)
    : m_initialized(false)
    , m_switch(std::make_shared<vif_switch<netif*>>())
{
    /* Check to see if we have permissions to launch DPDK */
    if (!sufficient_permissions()) {
        throw std::runtime_error("Insufficient permissions to initialize DPDK");
    }

    /* Convert args to c-strings for DPDK consumption */
    std::vector<char *> eal_args;
    eal_args.reserve(args.size() + 1);
    std::transform(begin(args), end(args), std::back_inserter(eal_args),
                   [](std::string &s) { return s.data(); });
    eal_args.push_back(nullptr); /* null terminator */

    ICP_LOG(ICP_LOG_INFO, "Initializing DPDK with \\\"%s\\\"\n",
            std::accumulate(begin(args), end(args), std::string(),
                            [](const std::string &a, const std::string &b) -> std::string {
                                return a + (a.length() > 0 ? " " : "") + b;
                            }).c_str());

    /* Create a stream for the EAL to use that forwards its messages to our logger */
    cookie_io_functions_t stream_functions = {
        .write = eal_log_write
    };

    auto stream = fopencookie(nullptr, "w+", stream_functions);
    if (!stream || rte_openlog_stream(stream) < 0) {
        throw std::runtime_error("Failed to set DPDK log stream");
    }

    int parsed_or_err = rte_eal_init(eal_args.size() - 1, eal_args.data());
    if (parsed_or_err < 0) {
        throw std::runtime_error("Failed to initialize DPDK");
    }

    m_initialized = true;

    /*
     * rte_eal_init returns the number of parsed arguments; warn if some arguments were
     * unparsed.  We subtract two to account for the trailing null and the program name.
     */
    if (parsed_or_err != static_cast<int>(eal_args.size() - 2)) {
        ICP_LOG(ICP_LOG_ERROR, "DPDK initialization routine only parsed %d of %" PRIu64 " arguments\n",
                parsed_or_err, eal_args.size() - 2);
    } else {
        ICP_LOG(ICP_LOG_INFO, "DPDK initialized (%d workers available)\n", eal_workers());
    }

    /*
     * Loop through our available ports and...
     * 1. Log the MAC/driver to the console
     * 2. Generate a port_info vector
     */
    uint16_t port_id = 0;
    std::vector<model::port_info> port_info;
    RTE_ETH_FOREACH_DEV(port_id) {
        port_info.emplace_back(model::port_info(port_id));
        log_port(port_id, port_info.back());
    }

    /* Use the port_info vector to allocate our default memory pools */
    m_allocator = std::make_unique<pool_allocator>(pool_allocator(port_info));

    /* And determine how we should distribute port queues to workers */
    auto descriptors = queue::distribute_queues(port_info, eal_workers() - 1);

    /* Use the queue descriptors to configure all of our ports */
    configure_all_ports(get_port_queue_counts(descriptors),
                        m_allocator->rx_mempool());


    /* Finally, launch work threads on all of our available worker cores */
    m_workers = std::make_unique<worker::client>(context, eal_workers() - 1);
    static std::string_view sync_endpoint = "inproc://eal_worker_sync";
    auto sync = icp_task_sync_socket(context, sync_endpoint.data());
    struct worker::args worker_args = {
        .context = context,
        .endpoint = sync_endpoint.data(),
        .vif = m_switch
    };

    std::unordered_map<int, int> worker_lcore_map;
    for (int i = 0; i < eal_workers() - 1; i++) {
        /* Generate a map from worker index to lcore id; we'll use this later */
        worker_lcore_map[i] = get_waiting_lcore();
        rte_eal_remote_launch(worker::main, &worker_args, worker_lcore_map[i]);
    }

    /*
     * Wait until all workers have pinged us back.  If we send out the configuration
     * before all of the workers are ready, they could miss it.
     */
    icp_task_sync_block(&sync, eal_workers() - 1);

    /*
     * Update our descriptor configuration so that the worker id points to the actual,
     * in-use ids instead of our theoretical fantasy ones.
     */
    for (auto& d : descriptors) {
        d.worker_id = worker_lcore_map[d.worker_id];
    }
    m_workers->configure(descriptors);

    /* Finally, register a callback to log link status changes and start our ports. */
    if (int error = rte_eth_dev_callback_register(RTE_ETH_ALL, RTE_ETH_EVENT_INTR_LSC,
                                                  log_link_status_change, nullptr);
        error != 0) {
        ICP_LOG(ICP_LOG_WARNING, "Could not register link status change callback: %s\n",
                strerror(std::abs(error)));
    }

    start();
}

eal::~eal()
{
    if (!m_initialized) {
        return;
    }

    stop();

    rte_eth_dev_callback_unregister(RTE_ETH_ALL, RTE_ETH_EVENT_INTR_LSC,
                                    log_link_status_change, nullptr);

    /* Shut up clang's warning about this being an unstable ABI function */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    rte_eal_cleanup();
#pragma clang diagnostic pop
};

void eal::start()
{
    uint16_t port_id = 0;
    RTE_ETH_FOREACH_DEV(port_id) {
        model::physical_port(port_id).start();
    }
    m_workers->start();
}

void eal::stop()
{
    m_workers->stop();
    uint16_t port_id = 0;
    RTE_ETH_FOREACH_DEV(port_id) {
        model::physical_port(port_id).stop();
    }
}

std::vector<int> eal::port_ids()
{
    uint16_t port_idx = 0;
    std::vector<int> port_ids;
    RTE_ETH_FOREACH_DEV(port_idx) {
        port_ids.emplace_back(port_idx);
    }

    return (port_ids);
}

std::optional<port::generic_port> eal::port(int id) const
{
    return (rte_eth_dev_is_valid_port(id)
            ? std::make_optional(port::generic_port(model::physical_port(id, m_allocator->rx_mempool())))
            : std::nullopt);
}

tl::expected<int, std::string> eal::create_port(const port::config_data& config)
{
    static int idx = 0;

    /* Sanity check input */
    if (!std::holds_alternative<port::bond_config>(config)) {
        return tl::make_unexpected("Missing bond configuration data");
    }

    /* Make sure that all ports in the vector actually exist */
    for (auto id : std::get<port::bond_config>(config).ports) {
        if (!rte_eth_dev_is_valid_port(id)) {
            return tl::make_unexpected("Port id " + std::to_string(id) + " is invalid");
        }
    }

    /* Well all right.  Let's create a port, shall we? */
    /*
     * XXX: DPDK uses the prefix of the name to find the proper driver;
     * ergo, this name cannot change.
     */
    std::string name = "net_bonding" + std::to_string(idx++);
    /**
     * XXX: The 3rd parameter _should_ be SOCKET_ID_ANY, since we don't care
     * about NUMA yet, however, the DPDK function signature's are screwed up.
     * This create function takes a uint8_t for the socket id, but the rest of
     * the DPDK code uses an int for the socket id.
     * So... we have to use 0 here so that we don't attempt to allocate memory
     * from NUMA socket 255.
     */
    int id_or_error = rte_eth_bond_create(name.c_str(),
                                          BONDING_MODE_8023AD,
                                          0);
    if (id_or_error < 0) {
        return tl::make_unexpected("Failed to create bond port: "
                                   + std::string(rte_strerror(std::abs(id_or_error))));
    }

    std::vector<int> success_record;
    for(auto id : std::get<port::bond_config>(config).ports) {
        int error = rte_eth_bond_slave_add(id_or_error, id);
        if (error) {
            for (auto added_id : success_record) {
                rte_eth_bond_slave_remove(id_or_error, added_id);
            }
            rte_eth_bond_free(name.c_str());
            return tl::make_unexpected("Failed to add slave port " + std::to_string(id)
                                       + "to bond port " + std::to_string(id_or_error)
                                       + ": " + std::string(rte_strerror(std::abs(error))));
        }
        success_record.push_back(id);
    }

    m_bond_ports[id_or_error] = name;
    return (id_or_error);
}

tl::expected<void, std::string> eal::delete_port(int id)
{
    if (!rte_eth_dev_is_valid_port(id)) {
        /* Deleting a non-existent port is fine */
        return {};
    }

    /* Port exists */
    if (m_bond_ports.find(id) == m_bond_ports.end()) {
        /* but it's not one we can delete */
        return tl::unexpected("Port " + std::to_string(id) + " cannot be deleted");
    }

    /*
     * There is apparently no way to query the number of slaves a port has,
     * so resort to brute force here.
     */
    uint16_t slaves[RTE_MAX_ETHPORTS] = {};
    int length_or_err = rte_eth_bond_slaves_get(id, slaves, RTE_MAX_ETHPORTS);
    if (length_or_err < 0) {
        /* Not sure what else we can do here... */
        ICP_LOG(ICP_LOG_ERROR, "Could not retrieve slave port ids from bonded port %d\n", id);
    } else if (length_or_err > 0) {
        for (int i = 0; i < length_or_err; i++) {
            rte_eth_bond_slave_remove(id, i);
        }
    }
    rte_eth_bond_free(m_bond_ports[id].c_str());
    m_bond_ports.erase(id);
    return {};
}

void eal::add_interface(int id, std::any interface)
{
    if (!rte_eth_dev_is_valid_port(id)) {
        throw std::runtime_error("Port id " + std::to_string(id) + " is invalid");
    }

    /* We really only expect one type here */
    auto ifp = std::any_cast<netif*>(interface);
    auto mac = net::mac_address(ifp->hwaddr);

    m_workers->stop();
    model::physical_port(id).add_mac_address(mac);
    m_switch->insert(id, mac, ifp);
    m_workers->start();

    if (!m_switch->unicast_find(id, ifp->hwaddr)) {
        throw std::runtime_error("Could not find interface mac in switch");
    }

    ICP_LOG(ICP_LOG_DEBUG, "Added interface with mac = %s to port %d\n",
            net::to_string(net::mac_address(ifp->hwaddr)).c_str(), id);
}

void eal::del_interface(int id, std::any interface)
{
    if (!rte_eth_dev_is_valid_port(id)) {
        throw std::runtime_error("Port id " + std::to_string(id) + " is invalid");
    }

    /* We really only expect one type here */
    auto ifp = std::any_cast<netif*>(interface);
    auto mac = net::mac_address(ifp->hwaddr);
    m_workers->stop();
    model::physical_port(id).del_mac_address(mac);
    m_switch->erase(id, mac, ifp);
    m_workers->start();

    ICP_LOG(ICP_LOG_DEBUG, "Deleted interface with mac = %s from port %d\n",
            net::to_string(net::mac_address(ifp->hwaddr)).c_str(), id);
}

}
}
}
