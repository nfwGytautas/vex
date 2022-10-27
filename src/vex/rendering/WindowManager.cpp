/**
 * @file WindowManager.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "WindowManager.h"

#include <glad/glad.h>
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

    // 4.1 max version supported by macOS
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    return true;
}

void WindowManager::shutdown() {
    LOG_TRACE("Window manager shutting down");

    glfwTerminate();
}

void WindowManager::pollEvents() {
    glfwPollEvents();
}

WindowManager& WindowManager::getInstance() {
    static WindowManager manager;
    return manager;
}

} // namespace rendering
} // namespace vex