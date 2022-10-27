/**
 * @file Window.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Window.h"

#include <glad/glad.h>

namespace vex {
namespace ui {

void Window::setTitle(const std::string& title) {
    m_title = title;

    if (isCreated()) {
        GfxWindow::setTitle(m_title.c_str());
    }
}

void Window::create() {
    GfxWindow::create();

    // Set the initial data
    GfxWindow::setTitle(m_title.c_str());
}

void Window::render() {
    glClearColor(0.5, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace ui
} // namespace vex