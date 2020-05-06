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
 * TrafficDuration_time.h
 *
 * Describes the transmit time
 */

#ifndef TrafficDuration_time_H_
#define TrafficDuration_time_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Describes the transmit time
/// </summary>
class  TrafficDuration_time
    : public ModelBase
{
public:
    TrafficDuration_time();
    virtual ~TrafficDuration_time();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TrafficDuration_time members

    /// <summary>
    /// Specifies the value for time based transmission
    /// </summary>
    int32_t getValue() const;
    void setValue(int32_t value);
        /// <summary>
    /// Specifies the units for value
    /// </summary>
    std::string getUnits() const;
    void setUnits(std::string value);
    
protected:
    int32_t m_Value;

    std::string m_Units;

};

}
}
}

#endif /* TrafficDuration_time_H_ */