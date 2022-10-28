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
    m_requiresDataUpdate = true;
}

void Window::render() {
    m_gfx->makeCurrent();

    if (m_requiresDataUpdate) {
        updateGfxWindowData();
    }

    // Rendering goes here
    glClearColor(m_bgColor.R, m_bgColor.G, m_bgColor.B, m_bgColor.A);
    glClear(GL_COLOR_BUFFER_BIT);

    m_gfx->swapBuffers();
}

void Window::setBackgroundColor(vex::ui::Color color) {
    m_bgColor = color;
}

void Window::setGfxWindow(rendering::GfxWindow* window) {
    m_gfx = window;
    m_requiresDataUpdate = true;
}

void Window::updateGfxWindowData() {
    m_gfx->setTitle(m_title.c_str());
    m_gfx->setSize(m_size);
    m_requiresDataUpdate = false;
}

void Window::setSize(const glm::vec2& size) {
    m_size = size;
    m_requiresDataUpdate = true;
}

} // namespace ui
} // namespace vex