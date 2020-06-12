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
 * BulkStartPacketAnalyzersResponse.h
 *
 * 
 */

#ifndef BulkStartPacketAnalyzersResponse_H_
#define BulkStartPacketAnalyzersResponse_H_


#include "ModelBase.h"

#include <vector>
#include "PacketAnalyzerResult.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// 
/// </summary>
class  BulkStartPacketAnalyzersResponse
    : public ModelBase
{
public:
    BulkStartPacketAnalyzersResponse();
    virtual ~BulkStartPacketAnalyzersResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BulkStartPacketAnalyzersResponse members

    /// <summary>
    /// List of analyzer results
    /// </summary>
    std::vector<std::shared_ptr<PacketAnalyzerResult>>& getItems();
    
protected:
    std::vector<std::shared_ptr<PacketAnalyzerResult>> m_Items;

};

}
}
}

#endif /* BulkStartPacketAnalyzersResponse_H_ */