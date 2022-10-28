/**
 * @file Application.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Application.h"

#include "vex/rendering/WindowManager.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace ui {

Application::~Application() {}

void Application::addWindow(vex::ui::Window* pWindow) {
    m_windows.push_back(pWindow);
}

void Application::render() {
    for (Window* window : m_windows) {
        window->render();
    }
}

void Application::shutdown() {
    for (Window* window : m_windows) {
        delete window;
    }

    m_windows.clear();
    rendering::WindowManager::getInstance().resetWindowCount();
}

void Application::initialize() {
    // Setup windows
    for (Window* window : m_windows) {
        window->setGfxWindow(rendering::WindowManager::getInstance().createWindow());
    }
}

bool Application::doesAppWantsToClose() const {
    return m_shutdown;
}

} // namespace ui
} // namespace vex