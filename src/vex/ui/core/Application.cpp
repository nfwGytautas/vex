/**
 * @file Application.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Application.h"

namespace vex {
namespace ui {

Application::~Application() {}

void Application::addWindow(vex::ui::Window* pWindow) {
    m_windows.push_back(pWindow);
}

void Application::start() {
    // Setup systems
    if (!m_windowManager.initialize()) {
        return;
    }

    // Setup windows
    for (Window* window : m_windows) {
        window->create();
    }

    while (!m_shutdown) {
        m_windowManager.pollEvents();
    }

    shutdown();

    // Shutdown systems
    m_windowManager.shutdown();
}

void Application::shutdown() {
    for (Window* window : m_windows) {
        window->destroy();
        delete window;
    }
}

} // namespace ui
} // namespace vex