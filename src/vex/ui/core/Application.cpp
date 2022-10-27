/**
 * @file Application.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Application.h"

#include "vex/rendering/Renderer.h"
#include "vex/rendering/WindowManager.h"

namespace vex {
namespace ui {

Application::~Application() {}

void Application::addWindow(vex::ui::Window* pWindow) {
    m_windows.push_back(pWindow);
}

void Application::start() {
    // Setup windows
    for (Window* window : m_windows) {
        window->create();
    }

    while (!m_shutdown) {
        rendering::WindowManager::getInstance().pollEvents();
        rendering::Renderer::getInstance().commit();
    }

    shutdown();
}

void Application::shutdown() {
    for (Window* window : m_windows) {
        window->destroy();
        delete window;
    }
}

} // namespace ui
} // namespace vex