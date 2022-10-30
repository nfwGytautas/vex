/**
 * @file WindowParsingFunction.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include "WindowParsingFunction.h"

#include "glm/vec2.hpp"
#include "vex/ui/common/Color.h"
#include "vex/ui/core/Window.h"
#include "vex/utility/Logger.h"
#include "vex/utility/Utility.h"

namespace vex {
namespace ui {
namespace parsers {

IParsingFunction* WindowParsingFunction::getInstance() {
    static WindowParsingFunction instance;
    return &instance;
}

bool WindowParsingFunction::canParse(const std::string& nodeName) {
    return nodeName == "Window";
}

bool WindowParsingFunction::parse(const pugi::xml_node& node, UIElement*& out) {
    auto* window = new ui::Window();

    // Attributes
    const auto& title = node.attribute("title");
    const auto& bgColor = node.attribute("bgColor");
    const auto& size = node.attribute("size");

    if (!title.empty()) {
        window->setTitle(title.value());
    }

    if (!bgColor.empty()) {
        ui::Color color {};

        if (!ui::Color::fromString(bgColor.value(), color)) {
            LOG_WARN("Invalid color string '{0}' at {1}", bgColor.value(), node.path());
        } else {
            window->setBackgroundColor(color);
        }
    }

    if (!size.empty()) {
        glm::vec2 sizeValue {};

        if (!utility::Utility::stringToVec2(size.value(), sizeValue)) {
            LOG_WARN("Invalid size string '{0}' at {1}", size.value(), node.path());
        } else {
            window->setSize(sizeValue);
        }
    } else {
        window->setSize({50, 50});
    }

    for (const pugi::xml_node& child : node.children()) {
        IParsingFunction* parser = getParser(child.name());

        if (parser == nullptr) {
            LOG_WARN("Unknown parser for element {0}, skipping", child.name());
            continue;
        }

        if (!isLayoutNode(child.name())) {
            LOG_ERROR("Window node can only have *Layout type elements");
            delete window;
            return false;
        } else {
            ui::UIElement* layout = nullptr;
            if (!parser->parse(child, layout)) {
                delete window;
                return false;
            }
            layout->setParent(window);
            window->setLayout(layout);
        }
    }

    out = window;

    return true;
}

} // namespace parsers
} // namespace ui
} // namespace vex