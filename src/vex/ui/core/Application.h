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
public:
    Application() = default;
    ~Application();

    /**
     * Render the application
     */
    void render();

    /**
     * Add a window to the application
     * @param pWindow Window pointer
     */
    void addWindow(vex::ui::Window* pWindow);

    /**
     * Shutdown the application
     */
    void shutdown();

    /**
     * Initialize the application
     */
    void initialize();

    /**
     * Returns true if the app code/user requested application shutdown
     */
    bool doesAppWantsToClose() const;

private:
    bool m_shutdown = false;
    std::vector<Window*> m_windows;
};

} // namespace ui
} // namespace vex
