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
 Name        : logger.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Utility for logging
 =================================================================================================================
*/

#pragma once
#include <spdlog/spdlog.h>
#include <string>

#define concat(var_1, var_2) var_1 var_2

#define LOG_DEBUG(exp_detail, log_msg) Logger::debug(exp_detail, log_msg, __FILE__, __LINE__)
#define LOG_INFO(exp_detail, log_msg) Logger::info(exp_detail, log_msg, __FILE__, __LINE__)
#define LOG_WARN(exp_detail, log_msg) Logger::warn(exp_detail, log_msg, __FILE__, __LINE__)
#define LOG_ERROR(exp_detail, log_msg) Logger::error(exp_detail, log_msg, __FILE__, __LINE__)

class Logger {
public:
    static std::shared_ptr<spdlog::logger>& get_instance();
    static void debug(const std::string& exp_detail, const std::string& log_msg, const char* file, int line);
    static void info(const std::string& exp_detail, const std::string& log_msg, const char* file, int line);
    static void warn(const std::string& exp_detail, const std::string& log_msg, const char* file, int line);
    static void error(const std::string& exp_detail, const std::string& log_msg, const char* file, int line);

private:
    static void init();
    static std::shared_ptr<spdlog::logger> logger_instance_;
};
