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
 * TrafficProtocolMacModifier.h
 *
 * Specifies how to modify an Ethernet MAC address
 */

#ifndef TrafficProtocolMacModifier_H_
#define TrafficProtocolMacModifier_H_


#include "ModelBase.h"

#include <string>
#include "TrafficProtocolMacModifier_sequence.h"
#include "MacAddress.h"
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Specifies how to modify an Ethernet MAC address
/// </summary>
class  TrafficProtocolMacModifier
    : public ModelBase
{
public:
    TrafficProtocolMacModifier();
    virtual ~TrafficProtocolMacModifier();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TrafficProtocolMacModifier members

    /// <summary>
    /// Modifier method
    /// </summary>
    std::string getMethod() const;
    void setMethod(std::string value);
        /// <summary>
    /// List of MAC addresses
    /// </summary>
    std::vector<std::shared_ptr<MacAddress>>& getList();
    bool listIsSet() const;
    void unsetList();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TrafficProtocolMacModifier_sequence> getSequence() const;
    void setSequence(std::shared_ptr<TrafficProtocolMacModifier_sequence> value);
    bool sequenceIsSet() const;
    void unsetSequence();

protected:
    std::string m_Method;

    std::vector<std::shared_ptr<MacAddress>> m_List;
    bool m_ListIsSet;
    std::shared_ptr<TrafficProtocolMacModifier_sequence> m_Sequence;
    bool m_SequenceIsSet;
};

}
}
}

#endif /* TrafficProtocolMacModifier_H_ */