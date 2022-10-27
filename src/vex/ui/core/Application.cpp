/**
 * @file Application.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Application.h"

namespace vex {
namespace ui {

Application::~Application() {
    for (Window* window : m_windows) {
        delete window;
    }
}

void Application::addWindow(vex::ui::Window* pWindow) {
    m_windows.push_back(pWindow);
}

} // namespace ui
} // namespace vex