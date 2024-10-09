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
 Name        : log_util.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Utility for logging
 =================================================================================================================
*/

#pragma once
#include <spdlog/spdlog.h>
#include <string>
#include <memory>
#include <mutex>

/**
* Macro to call method logger::debug to produce specific file and line when its called
* @param exp_detail exception detail as std::string
* @param log_msg log message as std::string
*/
#define LOG_DEBUG(exp_detail, log_msg) Logger::debug(exp_detail, log_msg, __FILE__, __LINE__)
/**
* Macro to call method logger::info to produce specific file and line when its called
* @param exp_detail exception detail as std::string
* @param log_msg log message as std::string
*/
#define LOG_INFO(exp_detail, log_msg) Logger::info(exp_detail, log_msg, __FILE__, __LINE__)
/**
* Macro to call method logger::warn to produce specific file and line when its called
* @param exp_detail exception detail as std::string
* @param log_msg log message as std::string
*/
#define LOG_WARN(exp_detail, log_msg) Logger::warn(exp_detail, log_msg, __FILE__, __LINE__)
/**
* Macro to call method logger::error to produce specific file and line when its called
* @param exp_detail exception detail as std::string
* @param log_msg log message as std::string
*/
#define LOG_ERROR(exp_detail, log_msg) Logger::error(exp_detail, log_msg, __FILE__, __LINE__)

class Logger {
public:
    /**
    * Method to get logger instance
    * @return logger instance as std::shared_ptr<spdlog::logger>
    */
    static std::shared_ptr<spdlog::logger>& get_instance();
    /**
    * Method to run debug logger
    * @param exp_detail exception detail as std::string
    * @param log_msg log message as std::string
    * @param file file address as pointer char
    * @param line line address as int32_t
    */
    static void debug(const std::string& exp_detail, const std::string& log_msg, const char* file, int32_t line);
    /**
    * Method to run debug info
    * @param exp_detail exception detail as std::string
    * @param log_msg log message as std::string
    * @param file file address as pointer char
    * @param line line address as int32_t
    */
    static void info(const std::string& exp_detail, const std::string& log_msg, const char* file, int32_t line);
    /**
    * Method to run debug warning
    * @param exp_detail exception detail as std::string
    * @param log_msg log message as std::string
    * @param file file address as pointer char
    * @param line line address as int32_t
    */
    static void warn(const std::string& exp_detail, const std::string& log_msg, const char* file, int32_t line);
    /**
    * Method to run debug error
    * @param exp_detail exception detail as std::string
    * @param log_msg log message as std::string
    * @param file file address as pointer char
    * @param line line address as int32_t
    */
    static void error(const std::string& exp_detail, const std::string& log_msg, const char* file, int32_t line);
private:
    /**
    * Method to get spdlog log level
    * @return spdlog log level as spdlog::level::level_enum
    */
    static spdlog::level::level_enum get_log_level();

    static inline std::shared_ptr<spdlog::logger> logger_instance_ = nullptr;
    static inline std::mutex logger_mutex_; 

    /**
    * Method to initialize logger instance
    */
    static void init();
};
