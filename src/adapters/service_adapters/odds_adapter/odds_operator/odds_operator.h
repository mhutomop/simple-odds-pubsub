/*
 * Copyright PT LEN INNOVATION TECHNOLOGY
 *
 * THIS SOFTWARE SOURCE CODE AND ANY EXECUTABLE DERIVED THEREOF ARE PROPRIETARY
 * TO PT LEN INNOVATION TECHNOLOGY, AS APPLICABLE, AND SHALL NOT BE USED IN ANY WAY
 * OTHER THAN BEFOREHAND AGREED ON BY PT LEN INNOVATION TECHNOLOGY, NOR BE REPRODUCED
 * OR DISCLOSED TO THIRD PARTIES WITHOUT PRIOR WRITTEN AUTHORIZATION BY
 * PT LEN INNOVATION TECHNOLOGY, AS APPLICABLE.
 */

/*
 =================================================================================================================
 Name        : odds_operator.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Operator of OpenDDS
 =================================================================================================================
*/

#pragma once
#include <string>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/StaticIncludes.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

class ODDSOperator
{
public:
    /**
    * Method to check the return status for errors. If there is an error, then terminate
    * @param status status code as DDS::ReturnCode_t
    * @param info info to be added in error message as pointer char
    */
    void check_status
    (
        const DDS::ReturnCode_t &status,
        const char* info
    ) const;
    /**
    * Method to check whether a valid handle has been returned. If not, then terminate
    * @param handle handle to be checked as generics (template)
    * @param info info to be added in error message as std::string_view
    */
    template<class T>
    void check_handle
    (
        T* handle,
        std::string_view info
    ) const;
private:
    std::array<std::string, 13> ret_code_name_ = {
        "DDS_RETCODE_OK", "DDS_RETCODE_ERROR", "DDS_RETCODE_UNSUPPORTED", 
        "DDS_RETCODE_BAD_PARAMETER", "DDS_RETCODE_PRECONDITION_NOT_MET",
        "DDS_RETCODE_OUT_OF_RESOURCES", "DDS_RETCODE_NOT_ENABLED", 
        "DDS_RETCODE_IMMUTABLE_POLICY", "DDS_RETCODE_INCONSISTENT_POLICY", 
        "DDS_RETCODE_ALREADY_DELETED", "DDS_RETCODE_TIMEOUT", "DDS_RETCODE_NO_DATA",
        "DDS_RETCODE_ILLEGAL_OPERATION"
    };
};
