/**
 * @file ButtonParsingFunction.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include "ButtonParsingFunction.h"

#include "vex/binding/CodeLoader.h"
#include "vex/ui/elements/Button.h"
#include "vex/utility/Logger.h"
#include "vex/utility/Utility.h"

namespace vex {
namespace ui {
namespace parsers {

IParsingFunction* ButtonParsingFunction::getInstance() {
    static ButtonParsingFunction instance;
    return &instance;
}

bool ButtonParsingFunction::canParse(const std::string& nodeName) {
    return "Button" == nodeName;
}

bool ButtonParsingFunction::parse(const pugi::xml_node& node, UIElement*& out) {
    ui::elements::Button* btn = new ui::elements::Button();

    const auto& size = node.attribute("size");
    const auto& position = node.attribute("position");
    const auto& onClick = node.attribute("onClick");

    if (!size.empty()) {
        glm::vec2 sizeValue {};

        if (!utility::Utility::stringToVec2(size.value(), sizeValue)) {
            LOG_WARN("Invalid size string '{0}' at {1}", size.value(), node.path());
        } else {
            btn->setSize(sizeValue);
        }
    } else {
        btn->setSize({50, 50});
    }

    if (!position.empty()) {
        glm::vec2 positionValue {};

        if (!utility::Utility::stringToVec2(position.value(), positionValue)) {
            LOG_WARN("Invalid position string '{0}' at {1}", position.value(), node.path());
        } else {
            btn->setPosition(positionValue);
        }
    }

    if (!onClick.empty()) {
        btn->setOnClick(binding::CodeLoader::getInstance().getButtonOnClickFunction(onClick.value()));
    }

    out = btn;
    return true;
}

} // namespace parsers
} // namespace ui
} // namespace vex