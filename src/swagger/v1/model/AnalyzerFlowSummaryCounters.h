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
 * AnalyzerFlowSummaryCounters.h
 *
 * Summary results for per-packet statistics
 */

#ifndef AnalyzerFlowSummaryCounters_H_
#define AnalyzerFlowSummaryCounters_H_


#include "ModelBase.h"


namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Summary results for per-packet statistics
/// </summary>
class  AnalyzerFlowSummaryCounters
    : public ModelBase
{
public:
    AnalyzerFlowSummaryCounters();
    virtual ~AnalyzerFlowSummaryCounters();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// AnalyzerFlowSummaryCounters members

    /// <summary>
    /// Minimum value
    /// </summary>
    int64_t getMin() const;
    void setMin(int64_t value);
    bool minIsSet() const;
    void unsetMin();
    /// <summary>
    /// Maximum value
    /// </summary>
    int64_t getMax() const;
    void setMax(int64_t value);
    bool maxIsSet() const;
    void unsetMax();
    /// <summary>
    /// Sum of all received values
    /// </summary>
    int64_t getTotal() const;
    void setTotal(int64_t value);
        /// <summary>
    /// Standard deviation of received values
    /// </summary>
    int64_t getStdDev() const;
    void setStdDev(int64_t value);
    bool stdDevIsSet() const;
    void unsetStd_dev();

protected:
    int64_t m_Min;
    bool m_MinIsSet;
    int64_t m_Max;
    bool m_MaxIsSet;
    int64_t m_Total;

    int64_t m_Std_dev;
    bool m_Std_devIsSet;
};

}
}
}

#endif /* AnalyzerFlowSummaryCounters_H_ */