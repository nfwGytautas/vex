/**
 * @file FreeLayoutParsingFunction.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include "FreeLayoutParsingFunction.h"

#include "vex/ui/layouts/FreeLayout.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace ui {
namespace parsers {

IParsingFunction* FreeLayoutParsingFunction::getInstance() {
    static FreeLayoutParsingFunction instance;
    return &instance;
}

bool FreeLayoutParsingFunction::canParse(const std::string& nodeName) {
    return "FreeLayout" == nodeName;
}

bool FreeLayoutParsingFunction::parse(const pugi::xml_node& node, UIElement*& out) {
    layout::FreeLayout* layout = new layout::FreeLayout();

    for (const pugi::xml_node& child : node.children()) {
        IParsingFunction* parser = getParser(child.name());

        if (parser == nullptr) {
            LOG_WARN("Unknown parser for element {0}, skipping", child.name());
            continue;
        }

        ui::UIElement* element = nullptr;
        if (!parser->parse(child, element)) {
            return false;
        }
        element->setParent(layout);
        layout->addElement(element);
    }

    out = layout;

    return true;
}

} // namespace parsers
} // namespace ui
} // namespace vex