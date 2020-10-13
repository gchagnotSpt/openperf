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


#include "TvlpProfile_memory.h"

namespace swagger {
namespace v1 {
namespace model {

TvlpProfile_memory::TvlpProfile_memory()
{
    
}

TvlpProfile_memory::~TvlpProfile_memory()
{
}

void TvlpProfile_memory::validate()
{
    // TODO: implement validation
}

nlohmann::json TvlpProfile_memory::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    {
        nlohmann::json jsonArray;
        for( auto& item : m_Series )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        val["series"] = jsonArray;
            }
    

    return val;
}

void TvlpProfile_memory::fromJson(nlohmann::json& val)
{
    {
        m_Series.clear();
        nlohmann::json jsonArray;
                for( auto& item : val["series"] )
        {
            
            if(item.is_null())
            {
                m_Series.push_back( std::shared_ptr<TvlpProfile_memory_series>(nullptr) );
            }
            else
            {
                std::shared_ptr<TvlpProfile_memory_series> newItem(new TvlpProfile_memory_series());
                newItem->fromJson(item);
                m_Series.push_back( newItem );
            }
            
        }
    }
    
}


std::vector<std::shared_ptr<TvlpProfile_memory_series>>& TvlpProfile_memory::getSeries()
{
    return m_Series;
}

}
}
}
