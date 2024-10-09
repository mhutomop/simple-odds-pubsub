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
 Name        : odds_operator.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Operator of OpenDDS
 =================================================================================================================
*/

#include "odds_operator.h"
#include <string>
#include "../../../../utils/log_util/log_util.h"

void ODDSOperator::check_status
(
    const DDS::ReturnCode_t &status,
    const char* info
) const
{
    if (status != DDS::RETCODE_OK && status != DDS::RETCODE_NO_DATA)
        LOG_ERROR("ODDS", "Error in " + std::string(info) + "with return code : " + this->ret_code_name_[status]);
}
