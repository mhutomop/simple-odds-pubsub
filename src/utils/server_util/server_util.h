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
 Name        : server_util.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Utility for supporting server functions
 =================================================================================================================
*/

#pragma once
#include <string>

class ServerUtil
{
public:
    /**
    * Method to convert seconds from epoch time to ISO 8601 string
    */
    static std::string get_iso_string(uint64_t seconds);

    /**
    * Method to get timestamp of current time
    * @return epoch time in milliseconds
    */
    static uint64_t get_timestamp_in_ms();

    /**
    * Method to get timestamp of current time
    * @return epoch time in seconds
    */
    static uint64_t get_timestamp_in_s();
};
