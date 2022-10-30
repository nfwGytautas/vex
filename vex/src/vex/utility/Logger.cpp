/**
 * @file Log.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Logger.h"

#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace vex {
namespace utility {

Logger* Logger::get() {
    static Logger instance;
    return &instance;
}

void Logger::init() {
    const std::string pattern = "[%T.%e] thread %-5t | %^%v%$";

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::trace);
    console_sink->set_pattern(pattern);

    m_logger = std::make_shared<spdlog::logger>("Vex", std::initializer_list<spdlog::sink_ptr> {console_sink});
    m_logger->set_level(spdlog::level::trace);
}

} // namespace utility
} // namespace vex