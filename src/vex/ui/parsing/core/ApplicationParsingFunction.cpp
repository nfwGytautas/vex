/**
 * @file ApplicationParsingFunction.cpp
 * @author nfwGytautas
 * @date 10/28/22
 */

#include "ApplicationParsingFunction.h"

#include "vex/Macros.h"
#include "vex/ui/core/Application.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace ui {
namespace parsers {

IParsingFunction* ApplicationParsingFunction::getInstance() {
    static ApplicationParsingFunction instance;
    return &instance;
}

bool ApplicationParsingFunction::canParse(const std::string& nodeName) {
    return nodeName == "Application";
}

bool ApplicationParsingFunction::parse(const pugi::xml_node& node, UIElement*& out) {
    ui::Application* app = new ui::Application();

    IParsingFunction* windowParser = getParser("Window");
    VEX_DYNAMIC_ASSERT(windowParser != nullptr, "Window parser not defined");

    // Windows
    for (const pugi::xml_node& window : node.child("Windows").children()) {
        if (std::string("Window") != window.name()) {
            LOG_ERROR("Windows node can only contain Window nodes");
            delete app;
            return false;
        }

        ui::UIElement* windowInstance = nullptr;
        if (!windowParser->parse(window, windowInstance)) {
            return false;
        }

        windowInstance->setParent(app);
        app->addWindow(dynamic_cast<ui::Window*>(windowInstance));
    }

    out = app;

    return true;
}

} // namespace parsers
} // namespace ui
} // namespace vex