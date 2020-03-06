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


#include "AnalyzerFlowCounters_interarrival.h"

namespace swagger {
namespace v1 {
namespace model {

AnalyzerFlowCounters_interarrival::AnalyzerFlowCounters_interarrival()
{
    m_Units = "";
    
}

AnalyzerFlowCounters_interarrival::~AnalyzerFlowCounters_interarrival()
{
}

void AnalyzerFlowCounters_interarrival::validate()
{
    // TODO: implement validation
}

nlohmann::json AnalyzerFlowCounters_interarrival::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["summary"] = ModelBase::toJson(m_Summary);
    val["units"] = ModelBase::toJson(m_Units);
    

    return val;
}

void AnalyzerFlowCounters_interarrival::fromJson(nlohmann::json& val)
{
    setUnits(val.at("units"));
    
}


std::shared_ptr<AnalyzerFlowSummaryCounters> AnalyzerFlowCounters_interarrival::getSummary() const
{
    return m_Summary;
}
void AnalyzerFlowCounters_interarrival::setSummary(std::shared_ptr<AnalyzerFlowSummaryCounters> value)
{
    m_Summary = value;
    
}
std::string AnalyzerFlowCounters_interarrival::getUnits() const
{
    return m_Units;
}
void AnalyzerFlowCounters_interarrival::setUnits(std::string value)
{
    m_Units = value;
    
}

}
}
}
