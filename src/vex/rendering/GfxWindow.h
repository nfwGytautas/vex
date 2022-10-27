/**
 * @file GfxWindow.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <glfw/glfw3.h>

namespace vex {
namespace rendering {

/**
 * @brief The implementation for window
 */
class GfxWindow {
public:
    GfxWindow() = default;
    virtual ~GfxWindow() = default;

    /**
     * Create the window objects
     */
    virtual void create();

    /**
     * Destroy the window object
     */
    virtual void destroy();

protected:
    /**
     * Returns true if the window is created, false otherwise
     */
    bool isCreated() const;

    /**
     * Set the title of the window
     * @param title New title of the window
     */
    void setTitle(const char* title) const;

private:
    GLFWwindow* m_window = nullptr;
};

} // namespace rendering
} // namespace vex
