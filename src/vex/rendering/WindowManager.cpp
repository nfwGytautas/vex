/**
 * @file WindowManager.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "WindowManager.h"

#include <glfw/glfw3.h>

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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    return true;
}

void WindowManager::shutdown() {
    LOG_TRACE("Window manager shutting down");

    glfwTerminate();
}

void WindowManager::pollEvents() {
    glfwPollEvents();
}

} // namespace rendering
} // namespace vex