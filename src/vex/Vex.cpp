/**
 * @file Vex.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Vex.h"

#include "vex/rendering/Renderer.h"
#include "vex/rendering/WindowManager.h"
#include "vex/ui/LayoutParser.h"
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

    {
        // Parse ui and begin vex application
        LayoutParser parser(m_projectRoot);
        if (!parser.parse(m_app)) {
            LOG_ERROR("Failed to parse Init.xml");
            return 0x2;
        }

        // Start the application
        m_app->start();

        // Free memory
        delete m_app;
    }

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

} // namespace vex