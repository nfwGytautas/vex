/**
 * @file Window.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Window.h"

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

} // namespace ui
} // namespace vex