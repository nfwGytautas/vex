/**
 * @file GfxWindow.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "GfxWindow.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "vex/utility/Logger.h"

namespace vex {
namespace rendering {

void GfxWindow::create() {
    m_window = glfwCreateWindow(48, 48, "GfxWindow", NULL, NULL);

    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        LOG_ERROR("Failed to load glad for window");
    }

    if (!m_window) {
        // TODO: Error handling
    }
}

void GfxWindow::setTitle(const char* title) const {
    glfwSetWindowTitle(m_window, title);
}

void GfxWindow::destroy() {
    glfwDestroyWindow(m_window);
}

bool GfxWindow::isCreated() const {
    return m_window != nullptr;
}

void GfxWindow::swapBuffers() {
    glfwSwapBuffers(m_window);
}

void GfxWindow::makeCurrent() {
    glfwMakeContextCurrent(m_window);
}

} // namespace rendering
} // namespace vex