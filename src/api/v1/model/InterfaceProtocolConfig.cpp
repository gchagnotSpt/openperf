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


#include "InterfaceProtocolConfig.h"

namespace icp {
namespace api {
namespace v1 {
namespace model {

InterfaceProtocolConfig::InterfaceProtocolConfig()
{
    m_EthIsSet = false;
    m_Ipv4IsSet = false;
    
}

InterfaceProtocolConfig::~InterfaceProtocolConfig()
{
}

void InterfaceProtocolConfig::validate()
{
    // TODO: implement validation
}

nlohmann::json InterfaceProtocolConfig::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_EthIsSet)
    {
        val["eth"] = ModelBase::toJson(m_Eth);
    }
    if(m_Ipv4IsSet)
    {
        val["ipv4"] = ModelBase::toJson(m_Ipv4);
    }
    

    return val;
}

void InterfaceProtocolConfig::fromJson(nlohmann::json& val)
{
    if(val.find("eth") != val.end())
    {
        if(!val["eth"].is_null())
        {
            std::shared_ptr<InterfaceProtocolConfig_eth> newItem(new InterfaceProtocolConfig_eth());
            newItem->fromJson(val["eth"]);
            setEth( newItem );
        }
        
    }
    if(val.find("ipv4") != val.end())
    {
        if(!val["ipv4"].is_null())
        {
            std::shared_ptr<InterfaceProtocolConfig_ipv4> newItem(new InterfaceProtocolConfig_ipv4());
            newItem->fromJson(val["ipv4"]);
            setIpv4( newItem );
        }
        
    }
    
}


std::shared_ptr<InterfaceProtocolConfig_eth> InterfaceProtocolConfig::getEth() const
{
    return m_Eth;
}
void InterfaceProtocolConfig::setEth(std::shared_ptr<InterfaceProtocolConfig_eth> value)
{
    m_Eth = value;
    m_EthIsSet = true;
}
bool InterfaceProtocolConfig::ethIsSet() const
{
    return m_EthIsSet;
}
void InterfaceProtocolConfig::unsetEth()
{
    m_EthIsSet = false;
}
std::shared_ptr<InterfaceProtocolConfig_ipv4> InterfaceProtocolConfig::getIpv4() const
{
    return m_Ipv4;
}
void InterfaceProtocolConfig::setIpv4(std::shared_ptr<InterfaceProtocolConfig_ipv4> value)
{
    m_Ipv4 = value;
    m_Ipv4IsSet = true;
}
bool InterfaceProtocolConfig::ipv4IsSet() const
{
    return m_Ipv4IsSet;
}
void InterfaceProtocolConfig::unsetIpv4()
{
    m_Ipv4IsSet = false;
}

}
}
}
}
