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


#include "Inline_response_200.h"

namespace swagger {
namespace v1 {
namespace model {

Inline_response_200::Inline_response_200()
{
    m_Cores = 0;
    m_CoresIsSet = false;
    m_Cache_line_size = 0L;
    m_Cache_line_sizeIsSet = false;
    m_Architecture = "";
    m_ArchitectureIsSet = false;
    
}

Inline_response_200::~Inline_response_200()
{
}

void Inline_response_200::validate()
{
    // TODO: implement validation
}

nlohmann::json Inline_response_200::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_CoresIsSet)
    {
        val["cores"] = m_Cores;
    }
    if(m_Cache_line_sizeIsSet)
    {
        val["cache_line_size"] = m_Cache_line_size;
    }
    if(m_ArchitectureIsSet)
    {
        val["architecture"] = ModelBase::toJson(m_Architecture);
    }
    

    return val;
}

void Inline_response_200::fromJson(nlohmann::json& val)
{
    if(val.find("cores") != val.end())
    {
        setCores(val.at("cores"));
    }
    if(val.find("cache_line_size") != val.end())
    {
        setCacheLineSize(val.at("cache_line_size"));
    }
    if(val.find("architecture") != val.end())
    {
        setArchitecture(val.at("architecture"));
        
    }
    
}


int32_t Inline_response_200::getCores() const
{
    return m_Cores;
}
void Inline_response_200::setCores(int32_t value)
{
    m_Cores = value;
    m_CoresIsSet = true;
}
bool Inline_response_200::coresIsSet() const
{
    return m_CoresIsSet;
}
void Inline_response_200::unsetCores()
{
    m_CoresIsSet = false;
}
int64_t Inline_response_200::getCacheLineSize() const
{
    return m_Cache_line_size;
}
void Inline_response_200::setCacheLineSize(int64_t value)
{
    m_Cache_line_size = value;
    m_Cache_line_sizeIsSet = true;
}
bool Inline_response_200::cacheLineSizeIsSet() const
{
    return m_Cache_line_sizeIsSet;
}
void Inline_response_200::unsetCache_line_size()
{
    m_Cache_line_sizeIsSet = false;
}
std::string Inline_response_200::getArchitecture() const
{
    return m_Architecture;
}
void Inline_response_200::setArchitecture(std::string value)
{
    m_Architecture = value;
    m_ArchitectureIsSet = true;
}
bool Inline_response_200::architectureIsSet() const
{
    return m_ArchitectureIsSet;
}
void Inline_response_200::unsetArchitecture()
{
    m_ArchitectureIsSet = false;
}

}
}
}
