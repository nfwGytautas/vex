/**
 * @file GfxWindow.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <glfw/glfw3.h>

#include "glm/vec2.hpp"

namespace vex {
namespace rendering {

/**
 * @brief The implementation for window
 */
class GfxWindow final {
public:
    GfxWindow() = default;
    virtual ~GfxWindow() = default;

    /**
     * Create the window objects
     */
    void create();

    /**
     * Destroy the window object
     */
    void destroy();

    /**
     * Swaps buffers for this window
     */
    void swapBuffers();

    /**
     * Makes the window context current
     */
    void makeCurrent();

    /**
     * Returns true if the window is created, false otherwise
     */
    bool isCreated() const;

    /**
     * Set the title of the window
     * @param title New title of the window
     */
    void setTitle(const char* title) const;

    /**
     * Set the size of the window
     * @param size new size of the window
     */
    void setSize(const glm::vec2& size);

private:
    GLFWwindow* m_window = nullptr;
};

} // namespace rendering
} // namespace vex
