/**
 * @file GfxWindow.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "GfxWindow.h"

namespace vex {
namespace rendering {

void GfxWindow::create() {
    m_window = glfwCreateWindow(48, 48, "GfxWindow", NULL, NULL);

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

} // namespace rendering
} // namespace vex