/**
 * @file Vex.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <filesystem>

#include <efsw/efsw.hpp>

#include "vex/ui/core/Application.h"

namespace vex {

/**
 * @brief The entry point class for Vex
 */
class Vex final : public efsw::FileWatchListener {
    /**
     * Time to wait before reloading the UI after a change (number of frames), this is to limit the creating and deleting of windows
     */
    static constexpr size_t ReloadTimeout = 60;

public:
    Vex() = default;
    ~Vex() = default;

    /**
     * Entry point for vex, pass cmd arguments to the function
     * @param argc Number of console arguments
     * @param argv Argument values
     * @return Error code
     */
    int start(int argc, char** argv);

private:
    /**
     * Parse console arguments
     * @param argc Number of console arguments
     * @param argv Argument values
     * @return true if arguments are valid, false otherwise
     */
    bool parseCmdArguments(int argc, char** argv);

    /**
     * Initialize rendering system
     */
    void initializeRendering();

    /**
     * Shutdown rendering system
     */
    void shutdownRendering();

    /**
     * efsw callback for file watcher
     */
    void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action,
                          std::string oldFilename) override;

    /**
     * Run the application instance
     */
    void runApplication();

    /**
     * Load application or keep previous instance if application cannot be parsed correctly
     */
    void loadApplication();

private:
    std::filesystem::path m_projectRoot;
    ui::Application* m_app = nullptr;
    efsw::FileWatcher m_projectWatcher;

    size_t m_loadTimeout = ReloadTimeout;
    bool m_appNeedsReload = true;
};

} // namespace vex
