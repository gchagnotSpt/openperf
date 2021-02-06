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
 * PacketGeneratorLearningResultIpv4.h
 *
 * Defines an IPv4 address MAC address pair.
 */

#ifndef PacketGeneratorLearningResultIpv4_H_
#define PacketGeneratorLearningResultIpv4_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Defines an IPv4 address MAC address pair.
/// </summary>
class  PacketGeneratorLearningResultIpv4
    : public ModelBase
{
public:
    PacketGeneratorLearningResultIpv4();
    virtual ~PacketGeneratorLearningResultIpv4();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// PacketGeneratorLearningResultIpv4 members

    /// <summary>
    /// IPv4 address.
    /// </summary>
    std::string getIpAddress() const;
    void setIpAddress(std::string value);
        /// <summary>
    /// MAC address of associated IPv4 address.
    /// </summary>
    std::string getMacAddress() const;
    void setMacAddress(std::string value);
    bool macAddressIsSet() const;
    void unsetMac_address();

protected:
    std::string m_Ip_address;

    std::string m_Mac_address;
    bool m_Mac_addressIsSet;
};

}
}
}

#endif /* PacketGeneratorLearningResultIpv4_H_ */