/**
 * @file WindowManager.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

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

private:
};

} // namespace rendering
} // namespace vex
