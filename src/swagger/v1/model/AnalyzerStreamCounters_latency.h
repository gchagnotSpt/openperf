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
 * AnalyzerStreamCounters_latency.h
 *
 * Latency result counters
 */

#ifndef AnalyzerStreamCounters_latency_H_
#define AnalyzerStreamCounters_latency_H_


#include "ModelBase.h"

#include "AnalyzerStreamSummaryCounters.h"
#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Latency result counters
/// </summary>
class  AnalyzerStreamCounters_latency
    : public ModelBase
{
public:
    AnalyzerStreamCounters_latency();
    virtual ~AnalyzerStreamCounters_latency();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// AnalyzerStreamCounters_latency members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<AnalyzerStreamSummaryCounters> getSummary() const;
    void setSummary(std::shared_ptr<AnalyzerStreamSummaryCounters> value);
        /// <summary>
    /// Latency measurement units
    /// </summary>
    std::string getUnits() const;
    void setUnits(std::string value);
    
protected:
    std::shared_ptr<AnalyzerStreamSummaryCounters> m_Summary;

    std::string m_Units;

};

}
}
}

#endif /* AnalyzerStreamCounters_latency_H_ */
