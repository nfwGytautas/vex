/**
 * @file WindowManager.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

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
     * Returns the native display handle only really needed for linux
     * @return X11 or Wayland display for Linux, NULL for every other platform
     */
    [[nodiscard]] void* getNativeDisplayHandle() const;

    /**
     * Get the default window of Vex applications
     */
    GfxWindow* getDefaultWindow();

private:
    GfxWindow* m_defaultWindow = nullptr;
};

} // namespace rendering
} // namespace vex
