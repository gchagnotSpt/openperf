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


#include "AnalyzerStreamCounters_interarrival.h"

namespace swagger {
namespace v1 {
namespace model {

AnalyzerStreamCounters_interarrival::AnalyzerStreamCounters_interarrival()
{
    m_Units = "";
    
}

AnalyzerStreamCounters_interarrival::~AnalyzerStreamCounters_interarrival()
{
}

void AnalyzerStreamCounters_interarrival::validate()
{
    // TODO: implement validation
}

nlohmann::json AnalyzerStreamCounters_interarrival::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["summary"] = ModelBase::toJson(m_Summary);
    val["units"] = ModelBase::toJson(m_Units);
    

    return val;
}

void AnalyzerStreamCounters_interarrival::fromJson(nlohmann::json& val)
{
    setUnits(val.at("units"));
    
}


std::shared_ptr<AnalyzerStreamSummaryCounters> AnalyzerStreamCounters_interarrival::getSummary() const
{
    return m_Summary;
}
void AnalyzerStreamCounters_interarrival::setSummary(std::shared_ptr<AnalyzerStreamSummaryCounters> value)
{
    m_Summary = value;
    
}
std::string AnalyzerStreamCounters_interarrival::getUnits() const
{
    return m_Units;
}
void AnalyzerStreamCounters_interarrival::setUnits(std::string value)
{
    m_Units = value;
    
}

}
}
}

