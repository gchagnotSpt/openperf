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
 * TrafficLoad.h
 *
 * Describes the transmit load of a packet generator
 */

#ifndef TrafficLoad_H_
#define TrafficLoad_H_


#include "ModelBase.h"

#include <string>
#include "TrafficLoad_rate.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Describes the transmit load of a packet generator
/// </summary>
class  TrafficLoad
    : public ModelBase
{
public:
    TrafficLoad();
    virtual ~TrafficLoad();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TrafficLoad members

    /// <summary>
    /// Tells the generator how many packets to transmit as part of an atomic transmit operation. Larger burst sizes are more efficient. 
    /// </summary>
    int32_t getBurstSize() const;
    void setBurstSize(int32_t value);
    bool burstSizeIsSet() const;
    void unsetBurst_size();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TrafficLoad_rate> getRate() const;
    void setRate(std::shared_ptr<TrafficLoad_rate> value);
        /// <summary>
    /// The transmit units for the packet generator
    /// </summary>
    std::string getUnits() const;
    void setUnits(std::string value);
    
protected:
    int32_t m_Burst_size;
    bool m_Burst_sizeIsSet;
    std::shared_ptr<TrafficLoad_rate> m_Rate;

    std::string m_Units;

};

}
}
}

#endif /* TrafficLoad_H_ */
