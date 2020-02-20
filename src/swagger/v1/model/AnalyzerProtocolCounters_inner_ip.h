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
 * AnalyzerProtocolCounters_inner_ip.h
 *
 * Inner layer 3 protocol counters
 */

#ifndef AnalyzerProtocolCounters_inner_ip_H_
#define AnalyzerProtocolCounters_inner_ip_H_


#include "ModelBase.h"


namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Inner layer 3 protocol counters
/// </summary>
class  AnalyzerProtocolCounters_inner_ip
    : public ModelBase
{
public:
    AnalyzerProtocolCounters_inner_ip();
    virtual ~AnalyzerProtocolCounters_inner_ip();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// AnalyzerProtocolCounters_inner_ip members

    /// <summary>
    /// Number of IPv4 packets without extensions
    /// </summary>
    int64_t getIpv4() const;
    void setIpv4(int64_t value);
        /// <summary>
    /// Number of IPv4 packets with well-known extensions
    /// </summary>
    int64_t getIpv4Ext() const;
    void setIpv4Ext(int64_t value);
        /// <summary>
    /// Number of IPv4 packets with unknown extensions
    /// </summary>
    int64_t getIpv4ExtUnknown() const;
    void setIpv4ExtUnknown(int64_t value);
        /// <summary>
    /// Number of IPv6 packets without extensions
    /// </summary>
    int64_t getIpv6() const;
    void setIpv6(int64_t value);
        /// <summary>
    /// Number of IPv6 packets with well-known extensions
    /// </summary>
    int64_t getIpv6Ext() const;
    void setIpv6Ext(int64_t value);
        /// <summary>
    /// Number of IPv6 packets with unknown extensions
    /// </summary>
    int64_t getIpv6ExtUnknown() const;
    void setIpv6ExtUnknown(int64_t value);
    
protected:
    int64_t m_Ipv4;

    int64_t m_Ipv4_ext;

    int64_t m_Ipv4_ext_unknown;

    int64_t m_Ipv6;

    int64_t m_Ipv6_ext;

    int64_t m_Ipv6_ext_unknown;

};

}
}
}

#endif /* AnalyzerProtocolCounters_inner_ip_H_ */
