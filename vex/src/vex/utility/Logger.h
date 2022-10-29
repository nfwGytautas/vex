/**
 * @file Log.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <memory>

#include <spdlog/spdlog.h>

namespace vex {
namespace utility {

/**
 * @brief Logging functionality using spdlog
 */
class Logger final {
public:
    /**
     * @brief Returns the logger instance
     */
    static Logger* get();

    /**
     * @brief Initializes logger, done automatically by the runtime
     */
    void init();

    // START OF SPDLOG INTERFACE

    template<typename... Args>
    void debug(Args&&... args) const {
        m_logger->debug(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void trace(Args&&... args) const {
        m_logger->trace(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void info(Args&&... args) const {
        m_logger->info(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void warn(Args&&... args) const {
        m_logger->warn(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void error(Args&&... args) const {
        m_logger->error(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void critical(Args&&... args) const {
        m_logger->critical(std::forward<Args>(args)...);
    }

    // END OF SPDLOG INTERFACE

    Logger(const Logger& o) = delete;

private:
    Logger() = default;
    std::shared_ptr<spdlog::logger> m_logger;
};

} // namespace utility
} // namespace vex

// Endpoint macros

// BLUE
#define LOG_DEBUG(...) ::vex::utility::Logger::get()->debug(__VA_ARGS__)

// WHITE
#define LOG_TRACE(...) ::vex::utility::Logger::get()->trace(__VA_ARGS__)

// GREEN
#define LOG_INFO(...) ::vex::utility::Logger::get()->info(__VA_ARGS__)

// YELLOW
#define LOG_WARN(...) ::vex::utility::Logger::get()->warn(__VA_ARGS__)

// RED
#define LOG_ERROR(...) ::vex::utility::Logger::get()->error(__VA_ARGS__)

// FATAL
#define LOG_FATAL(...) ::vex::utility::Logger::get()->critical(__VA_ARGS__)
