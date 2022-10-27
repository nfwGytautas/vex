/**
 * @file Application.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <filesystem>
#include <vector>

#include "Window.h"

namespace vex {
namespace ui {

/**
 * @brief Application is the main class for vex UI
 */
class Application final {
    /**
     * Time to wait before reloading the UI after a change (number of frames), this is to limit the creating and deleting of windows
     */
    static constexpr size_t ReloadTimeout = 60;

public:
    explicit Application(std::filesystem::path projectRoot);
    ~Application();

    /**
     * Start the application
     */
    void start();

    /**
     * Add a window to the application
     * @param pWindow Window pointer
     */
    void addWindow(vex::ui::Window* pWindow);

    /**
     * Load the application from Init.xml file
     */
    void load();

    /**
     * Marks the application that it needs to reload
     */
    void markForReload();

private:
    /**
     * Shutdown the application
     */
    void shutdown();

    /**
     * Initialize the application
     */
    void initialize();

private:
    std::filesystem::path m_projectRoot;
    bool m_shutdown = false;
    bool m_needsReload = false;
    std::vector<Window*> m_windows;
    size_t m_loadTimeout = ReloadTimeout;
};

} // namespace ui
} // namespace vex
