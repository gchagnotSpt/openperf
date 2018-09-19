/**
* Inception Core API
* REST API interface to the Inception Core
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/
/*
 * PortDriver_host.h
 *
 * Host-specific driver information
 */

#ifndef PortDriver_host_H_
#define PortDriver_host_H_


#include "ModelBase.h"

#include <string>

namespace icp {
namespace api {
namespace v1 {
namespace model {

/// <summary>
/// Host-specific driver information
/// </summary>
class  PortDriver_host
    : public ModelBase
{
public:
    PortDriver_host();
    virtual ~PortDriver_host();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// PortDriver_host members

    /// <summary>
    /// Host device name
    /// </summary>
    std::string getDeviceName() const;
    void setDeviceName(std::string value);
    
protected:
    std::string m_Device_name;

};

}
}
}
}

#endif /* PortDriver_host_H_ */