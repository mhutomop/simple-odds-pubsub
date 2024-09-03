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
 Name        : server_util.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Utility for supporting server functions
 =================================================================================================================
*/

#include "server_util.h"
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <chrono>

std::string ServerUtil::get_iso_string(uint64_t seconds) {
    return boost::posix_time::to_iso_extended_string(boost::posix_time::from_time_t(seconds)) + "Z";
}

uint64_t ServerUtil::get_timestamp_in_ms() {
    uint64_t current_milliseconds = 
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return current_milliseconds;
}

uint64_t ServerUtil::get_timestamp_in_s() {
    uint64_t current_seconds = 
        std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return current_seconds;
}
