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
 * Interface_config.h
 *
 * Interface configuration
 */

#ifndef Interface_config_H_
#define Interface_config_H_


#include "ModelBase.h"

#include "InterfaceProtocolConfig.h"
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Interface configuration
/// </summary>
class  Interface_config
    : public ModelBase
{
public:
    Interface_config();
    virtual ~Interface_config();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// Interface_config members

    /// <summary>
    /// A stack of protocol configurations, beginning with the outermost protocol (i.e. closest to the physical port) 
    /// </summary>
    std::vector<std::shared_ptr<InterfaceProtocolConfig>>& getProtocols();
    
protected:
    std::vector<std::shared_ptr<InterfaceProtocolConfig>> m_Protocols;

};

}
}
}

#endif /* Interface_config_H_ */
