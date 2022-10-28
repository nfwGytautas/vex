/**
 * @file WindowManager.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <vector>

#include "GfxWindow.h"

namespace vex {
namespace rendering {

/**
 * @brief Window manager
 */
class WindowManager final {
public:
    WindowManager() = default;
    ~WindowManager() = default;

    /**
     * Get singleton instance
     * @return WindowManager singleton instance
     */
    static WindowManager& getInstance();

    /**
     * Initializes the underlying window system
     * @return true if initialized, false otherwise
     */
    bool initialize();

    /**
     * Shutdown the window manager
     */
    void shutdown();

    /**
     * Polls events coming from OS to the windows
     */
    void pollEvents();

    /**
     * Creates a window or returns one from the window pool
     * @return GfxWindow instance pointer
     */
    GfxWindow* createWindow();

    /**
     * Resets the window counter
     */
    void resetWindowCount();

private:
    std::vector<GfxWindow*> m_windowPool;
    size_t m_numWindows = 0;
};

} // namespace rendering
} // namespace vex
