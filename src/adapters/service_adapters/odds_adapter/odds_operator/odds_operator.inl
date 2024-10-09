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
 Description : Operator of OpenDDS (template definition)
 =================================================================================================================
*/

#include "odds_operator.h"
#include <string>
#include "../../../../utils/log_util/log_util.h"

template<class T>
void ODDSOperator::check_handle
(
    T* handle,
    std::string_view info
) const
{
    if (!handle)
        LOG_ERROR("ODDS", "Error in " + static_cast<std::string>(info) + ": Creation failed: invalid handle");
}
