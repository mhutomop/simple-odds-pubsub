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
 Name        : logger.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Utility for logging
 =================================================================================================================
*/

#include <iostream>
#include <chrono>
#include <sstream>
#include "logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "../../globals/constants.h"

std::shared_ptr<spdlog::logger> Logger::logger_instance_ = nullptr;

void Logger::init() {
    if (!logger_instance_) {
        try {
            std::string pattern = "%H:%M:%S.%e [thread %t] %^%-7l%$ %g:%# %v";

            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            console_sink->set_pattern(pattern);

            std::string base_filename = std::string(kServiceName) + "_";

            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm tm;
            localtime_r(&now, &tm);
            std::stringstream ss;
            ss << std::put_time(&tm, "%Y-%m-%d");

            std::string filename_pattern = "logs/" + base_filename + ss.str() + ".log";

            auto file_sink = std::make_shared<spdlog::sinks::daily_file_format_sink_mt>(filename_pattern, 0, 0);
            file_sink->set_pattern(pattern);

            std::vector<spdlog::sink_ptr> sinks{ console_sink, file_sink };
            logger_instance_ = std::make_shared<spdlog::logger>("log", sinks.begin(), sinks.end());
            logger_instance_->set_level(spdlog::level::debug);
            logger_instance_->flush_on(spdlog::level::debug);
            spdlog::register_logger(logger_instance_);    
        } catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        }
    }
}

std::shared_ptr<spdlog::logger>& Logger::get_instance() {
    if (!logger_instance_) {
        init();
    }

    return logger_instance_;
}

void Logger::debug(const std::string& exp_detail, const std::string& log_msg, const char* file, int line) {
    get_instance()->log(spdlog::source_loc{file, line, SPDLOG_FUNCTION}, spdlog::level::debug, exp_detail + " - " + log_msg);
}

void Logger::info(const std::string& exp_detail, const std::string& log_msg, const char* file, int line) {
    get_instance()->log(spdlog::source_loc{file, line, SPDLOG_FUNCTION}, spdlog::level::info, exp_detail + " - " + log_msg);
}

void Logger::warn(const std::string& exp_detail, const std::string& log_msg, const char* file, int line) {
    get_instance()->log(spdlog::source_loc{file, line, SPDLOG_FUNCTION}, spdlog::level::warn, exp_detail + " - " + log_msg);
}

void Logger::error(const std::string& exp_detail, const std::string& log_msg, const char* file, int line) {
    get_instance()->log(spdlog::source_loc{file, line, SPDLOG_FUNCTION}, spdlog::level::err, exp_detail + " - " + log_msg);
}
