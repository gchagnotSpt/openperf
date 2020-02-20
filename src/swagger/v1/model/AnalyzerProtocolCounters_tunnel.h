/**
* OpenPerf API
* REST API interface for OpenPerf
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/
/*
 * AnalyzerProtocolCounters_tunnel.h
 *
 * Tunnel protocol counters
 */

#ifndef AnalyzerProtocolCounters_tunnel_H_
#define AnalyzerProtocolCounters_tunnel_H_


#include "ModelBase.h"


namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Tunnel protocol counters
/// </summary>
class  AnalyzerProtocolCounters_tunnel
    : public ModelBase
{
public:
    AnalyzerProtocolCounters_tunnel();
    virtual ~AnalyzerProtocolCounters_tunnel();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// AnalyzerProtocolCounters_tunnel members

    /// <summary>
    /// Number of IP in IP packets
    /// </summary>
    int64_t getIp() const;
    void setIp(int64_t value);
        /// <summary>
    /// Number of Generic Routing Encapsulation packets
    /// </summary>
    int64_t getGre() const;
    void setGre(int64_t value);
        /// <summary>
    /// Number of Virtual eXtensible LAN packets
    /// </summary>
    int64_t getVxlan() const;
    void setVxlan(int64_t value);
        /// <summary>
    /// Number of Network Virtualization using GRE packets
    /// </summary>
    int64_t getNvgre() const;
    void setNvgre(int64_t value);
        /// <summary>
    /// Number of Generic Network Virtualization Encapsulation packets
    /// </summary>
    int64_t getGeneve() const;
    void setGeneve(int64_t value);
        /// <summary>
    /// Number of Teredo, VXLAN, or GRE packets on limited hardware
    /// </summary>
    int64_t getGrenat() const;
    void setGrenat(int64_t value);
        /// <summary>
    /// Number of GPRS Tunneling Protocol control packets
    /// </summary>
    int64_t getGtpc() const;
    void setGtpc(int64_t value);
        /// <summary>
    /// Number of GPRS Tunneling Protocol user packets
    /// </summary>
    int64_t getGtpu() const;
    void setGtpu(int64_t value);
        /// <summary>
    /// Number of IP Encapsulating Security Payload packets
    /// </summary>
    int64_t getEsp() const;
    void setEsp(int64_t value);
        /// <summary>
    /// Number of Layer 2 Tunneling Protocol packets
    /// </summary>
    int64_t getL2tp() const;
    void setL2tp(int64_t value);
        /// <summary>
    /// Number of VXLAN Generic Protocol Extension packets
    /// </summary>
    int64_t getVxlanGpe() const;
    void setVxlanGpe(int64_t value);
        /// <summary>
    /// Number of MPLS-in-GRE packets (RFC 4023)
    /// </summary>
    int64_t getMplsInGre() const;
    void setMplsInGre(int64_t value);
        /// <summary>
    /// Number of MPLS-in-UDP packets (RFC 7510)
    /// </summary>
    int64_t getMplsInUdp() const;
    void setMplsInUdp(int64_t value);
    
protected:
    int64_t m_Ip;

    int64_t m_Gre;

    int64_t m_Vxlan;

    int64_t m_Nvgre;

    int64_t m_Geneve;

    int64_t m_Grenat;

    int64_t m_Gtpc;

    int64_t m_Gtpu;

    int64_t m_Esp;

    int64_t m_L2tp;

    int64_t m_Vxlan_gpe;

    int64_t m_Mpls_in_gre;

    int64_t m_Mpls_in_udp;

};

}
}
}

#endif /* AnalyzerProtocolCounters_tunnel_H_ */
