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
 * BlockGeneratorConfig.h
 *
 * Block generator configuration
 */

#ifndef BlockGeneratorConfig_H_
#define BlockGeneratorConfig_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Block generator configuration
/// </summary>
class  BlockGeneratorConfig
    : public ModelBase
{
public:
    BlockGeneratorConfig();
    virtual ~BlockGeneratorConfig();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BlockGeneratorConfig members

    /// <summary>
    /// Number of simultaneous (asynchronous) operations
    /// </summary>
    int32_t getQueueDepth() const;
    void setQueueDepth(int32_t value);
        /// <summary>
    /// Number of read operations to perform per second
    /// </summary>
    int32_t getReadsPerSec() const;
    void setReadsPerSec(int32_t value);
        /// <summary>
    /// Number of bytes to use for each read operation
    /// </summary>
    int32_t getReadSize() const;
    void setReadSize(int32_t value);
        /// <summary>
    /// Number of write operations to perform per second
    /// </summary>
    int32_t getWritesPerSec() const;
    void setWritesPerSec(int32_t value);
        /// <summary>
    /// Number of bytes to use for each write operation
    /// </summary>
    int32_t getWriteSize() const;
    void setWriteSize(int32_t value);
        /// <summary>
    /// IO access pattern
    /// </summary>
    std::string getPattern() const;
    void setPattern(std::string value);
    
protected:
    int32_t m_Queue_depth;

    int32_t m_Reads_per_sec;

    int32_t m_Read_size;

    int32_t m_Writes_per_sec;

    int32_t m_Write_size;

    std::string m_Pattern;

};

}
}
}

#endif /* BlockGeneratorConfig_H_ */