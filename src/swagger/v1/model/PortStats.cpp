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


#include "PortStats.h"

namespace swagger {
namespace v1 {
namespace model {

PortStats::PortStats()
{
    m_Rx_packets = 0L;
    m_Tx_packets = 0L;
    m_Rx_bytes = 0L;
    m_Tx_bytes = 0L;
    m_Rx_errors = 0L;
    m_Tx_errors = 0L;
    
}

PortStats::~PortStats()
{
}

void PortStats::validate()
{
    // TODO: implement validation
}

nlohmann::json PortStats::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["rx_packets"] = m_Rx_packets;
    val["tx_packets"] = m_Tx_packets;
    val["rx_bytes"] = m_Rx_bytes;
    val["tx_bytes"] = m_Tx_bytes;
    val["rx_errors"] = m_Rx_errors;
    val["tx_errors"] = m_Tx_errors;
    

    return val;
}

void PortStats::fromJson(nlohmann::json& val)
{
    setRxPackets(val.at("rx_packets"));
    setTxPackets(val.at("tx_packets"));
    setRxBytes(val.at("rx_bytes"));
    setTxBytes(val.at("tx_bytes"));
    setRxErrors(val.at("rx_errors"));
    setTxErrors(val.at("tx_errors"));
    
}


int64_t PortStats::getRxPackets() const
{
    return m_Rx_packets;
}
void PortStats::setRxPackets(int64_t value)
{
    m_Rx_packets = value;
    
}
int64_t PortStats::getTxPackets() const
{
    return m_Tx_packets;
}
void PortStats::setTxPackets(int64_t value)
{
    m_Tx_packets = value;
    
}
int64_t PortStats::getRxBytes() const
{
    return m_Rx_bytes;
}
void PortStats::setRxBytes(int64_t value)
{
    m_Rx_bytes = value;
    
}
int64_t PortStats::getTxBytes() const
{
    return m_Tx_bytes;
}
void PortStats::setTxBytes(int64_t value)
{
    m_Tx_bytes = value;
    
}
int64_t PortStats::getRxErrors() const
{
    return m_Rx_errors;
}
void PortStats::setRxErrors(int64_t value)
{
    m_Rx_errors = value;
    
}
int64_t PortStats::getTxErrors() const
{
    return m_Tx_errors;
}
void PortStats::setTxErrors(int64_t value)
{
    m_Tx_errors = value;
    
}

}
}
}

