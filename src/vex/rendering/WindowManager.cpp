/**
 * @file WindowManager.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "WindowManager.h"

#include <glfw/glfw3.h>

#define GLFW_EXPOSE_NATIVE_X11
#include <glfw/glfw3native.h>

#include "vex/utility/Logger.h"

namespace vex {
namespace rendering {

bool WindowManager::initialize() {
    LOG_TRACE("Initializing window manager");

    glfwSetErrorCallback([](int error, const char* description) {
        LOG_ERROR("[Window] GLFW error: {0}, {1}", error, description);
    });

    if (!glfwInit()) {
        LOG_ERROR("[Window] Failed to initialize GLFW");
        return false;
    }

    // Let bgfx take care of it
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create default window
    m_defaultWindow = new GfxWindow();
    m_defaultWindow->create();

    return true;
}

void WindowManager::shutdown() {
    LOG_TRACE("Window manager shutting down");

    m_defaultWindow->destroy();
    delete m_defaultWindow;

    glfwTerminate();
}

void WindowManager::pollEvents() {
    glfwPollEvents();
}

WindowManager& WindowManager::getInstance() {
    static WindowManager manager;
    return manager;
}

void* WindowManager::getNativeDisplayHandle() const {
    return glfwGetX11Display();
}

GfxWindow* WindowManager::getDefaultWindow() {
    return m_defaultWindow;
}

} // namespace rendering
} // namespace vex