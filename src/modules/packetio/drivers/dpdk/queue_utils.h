#ifndef _ICP_PACKETIO_DPDK_QUEUE_UTILS_H_
#define _ICP_PACKETIO_DPDK_QUEUE_UTILS_H_

#include <cstdint>
#include <vector>

namespace icp {
namespace packetio {
namespace dpdk {
namespace model {
class port_info;
}
namespace queue {

enum class queue_mode { NONE = 0,
                        RX,
                        TX,
                        RXTX };

/**
 * Structure describing how to configure port queues
 */
struct descriptor {
    uint16_t worker_id;    /**< worker id that should handle the specified queue */
    uint16_t port_id;      /**< queue's port id */
    uint16_t queue_id;     /**< queue's queue id */
    queue_mode mode;       /**< operational mode of queue for worker */
};

/**
 * Generate a distribution of port queues among the specified number of
 * {rx,tx} workers.
 *
 * @param[in] port_info
 *   A vector containing a port_info entry for every port
 * @param[in] q_workers
 *   The number of worker available for servicing port queues
 * @return
 *   A vector containing queue assignments for workers
 */
std::vector<descriptor> distribute_queues(const std::vector<model::port_info>& port_info, uint16_t q_workers);

}
}
}
}

#endif /* _ICP_PACKETIO_DPDK_QUEUE_UTILS_H_ */