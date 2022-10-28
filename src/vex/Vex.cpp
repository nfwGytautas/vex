/**
 * @file Vex.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Vex.h"
#include <iostream>

#include "vex/rendering/Renderer.h"
#include "vex/rendering/WindowManager.h"
#include "vex/ui/parsing/LayoutParser.h"
#include "vex/utility/Logger.h"

namespace vex {

int Vex::start(int argc, char** argv) {
    utility::Logger::get()->init();
    LOG_INFO("Vex starting");

    // Parse command line arguments
    if (!parseCmdArguments(argc, argv)) {
        return 0xFF;
    }

    LOG_TRACE("Command line arguments parsed");
    LOG_TRACE("\tProject root: {0}", m_projectRoot.c_str());

    // Now find Init.xml and parse it if it exists
    if (!std::filesystem::exists(m_projectRoot / "Init.xml")) {
        LOG_ERROR("Project root doesn't contain Init.xml file!");
        return 0x1;
    }

    // Initialize rendering
    initializeRendering();

    // Setup watcher
    efsw::WatchID watchId = m_projectWatcher.addWatch(m_projectRoot, this, true);

    // Start watching
    m_projectWatcher.watch();

    // Run application
    runApplication();

    // Shutdown rendering
    shutdownRendering();

    return 0;
}
bool Vex::parseCmdArguments(int argc, char** argv) {
    if (argc < 2) {
        // There is no way that there can exist an init file
        LOG_ERROR("Specify project directory");
        return false;
    }

    m_projectRoot = std::filesystem::path(argv[1]);

    if (!std::filesystem::is_directory(m_projectRoot)) {
        LOG_ERROR("Argument 1 needs to be a directory that points to the project root. Got: {0}", m_projectRoot.c_str());
        return false;
    }

    return true;
}

void Vex::initializeRendering() {
    rendering::WindowManager::getInstance().initialize();
    rendering::Renderer::getInstance().initialize();
}

void Vex::shutdownRendering() {
    rendering::Renderer::getInstance().shutdown();
    rendering::WindowManager::getInstance().shutdown();
}
void Vex::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action,
                           std::string oldFilename) {
    if (filename[filename.size() - 1] == '~') {
        return;
    }

    LOG_DEBUG("[Debug] Reloading");

    // Reload
    m_appNeedsReload = true;
}

void Vex::runApplication() {
    while (true) {
        rendering::WindowManager::getInstance().pollEvents();

        if (m_appNeedsReload) {
            loadApplication();
        }

        if (m_app != nullptr) {
            m_app->update();
            m_app->render();

            if (m_app->doesAppWantsToClose()) {
                break;
            }
        }

        rendering::Renderer::getInstance().commit();
    }

    delete m_app;
}

void Vex::loadApplication() {
    m_loadTimeout++;

    if (m_loadTimeout >= ReloadTimeout) {
        LOG_TRACE("Changes detected reloading application");
        ui::Application* newApp = new ui::Application();

        LayoutParser parser(m_projectRoot);
        if (!parser.parse(newApp)) {
            // Keep old application and delete the new
            LOG_ERROR("Failed parsing the application, keeping old instance");
            delete newApp;
        } else {
            LOG_TRACE("Switching application instance");

            if (m_app != nullptr) {
                m_app->shutdown();
            }

            newApp->initialize();

            if (m_app != nullptr) {
                m_app->shutdown();
                delete m_app;
            }

            m_app = newApp;
        }

        m_loadTimeout = 0;
        m_appNeedsReload = false;
    }
}

} // namespace vex