/**
 * @file Application.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Application.h"
#include <utility>

#include "vex/rendering/Renderer.h"
#include "vex/rendering/WindowManager.h"
#include "vex/ui/LayoutParser.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace ui {

Application::Application(std::filesystem::path projectRoot) : m_projectRoot(std::move(projectRoot)) {}

Application::~Application() {}

void Application::addWindow(vex::ui::Window* pWindow) {
    m_windows.push_back(pWindow);
}

void Application::start() {
    while (!m_shutdown) {
        rendering::WindowManager::getInstance().pollEvents();

        for (Window* window : m_windows) {
            window->makeCurrent();
            window->render();
            window->swapBuffers();
        }

        rendering::Renderer::getInstance().commit();

        if (m_needsReload) {
            this->load();
        }
    }
}

void Application::shutdown() {
    for (Window* window : m_windows) {
        window->destroy();
        delete window;
    }

    m_windows.clear();
}

void Application::load() {
    m_loadTimeout++;

    // TODO: Improve by removing unused windows after reload, saving on costly operations

    if (m_loadTimeout >= ReloadTimeout) {
        LOG_TRACE("Changes detected reloading application");
        shutdown();

        LayoutParser parser(m_projectRoot);
        if (!parser.parse(this)) {
            // TODO: Error parsing
        }

        initialize();

        m_loadTimeout = 0;
        m_needsReload = false;
    }
}

void Application::markForReload() {
    m_needsReload = true;
}

void Application::initialize() {
    // Setup windows
    for (Window* window : m_windows) {
        window->create();
    }
}

} // namespace ui
} // namespace vex