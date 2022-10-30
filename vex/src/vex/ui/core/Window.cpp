/**
 * @file Window.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Window.h"

#include <glad/glad.h>

namespace vex {
namespace ui {

Window::~Window() {
    if (m_layout != nullptr) {
        delete m_layout;
    }
}

void Window::setTitle(const std::string& title) {
    m_title = title;
}

void Window::update() {
    if (m_layout != nullptr) {
        m_layout->update();
    }
}

void Window::render() {
    m_gfx->makeCurrent();

    // Sync the data
    m_gfx->setTitle(m_title.c_str());
    m_gfx->setSize(p_size);

    // Rendering goes here
    glClearColor(m_bgColor.R, m_bgColor.G, m_bgColor.B, m_bgColor.A);
    glClear(GL_COLOR_BUFFER_BIT);

    if (m_layout != nullptr) {
        m_layout->render();
    }

    m_gfx->swapBuffers();
}

void Window::setBackgroundColor(vex::ui::Color color) {
    m_bgColor = color;
}

void Window::setGfxWindow(rendering::GfxWindow* window) {
    m_gfx = window;
}

void Window::setLayout(UIElement* layout) {
    m_layout = layout;
}

} // namespace ui
} // namespace vex