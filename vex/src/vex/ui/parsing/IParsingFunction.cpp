/**
 * @file IParsingFunction.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include "IParsingFunction.h"
#include <vector>

#include "vex/ui/parsing/core/ApplicationParsingFunction.h"
#include "vex/ui/parsing/core/WindowParsingFunction.h"
#include "vex/ui/parsing/elements/ButtonParsingFunction.h"
#include "vex/ui/parsing/layouts/FreeLayoutParsingFunction.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace ui {

const std::vector<ui::IParsingFunction*> s_parsingFunctions = {ui::parsers::ApplicationParsingFunction::getInstance(),
                                                               ui::parsers::WindowParsingFunction::getInstance(),
                                                               ui::parsers::FreeLayoutParsingFunction::getInstance(),
                                                               ui::parsers::ButtonParsingFunction::getInstance()};

IParsingFunction* IParsingFunction::getParser(const std::string& nodeName) {
    for (IParsingFunction* function : s_parsingFunctions) {
        if (function->canParse(nodeName)) {
            return function;
        }
    }

    LOG_ERROR("Parser for {0} not found", nodeName);

    return nullptr;
}

bool IParsingFunction::isLayoutNode(const std::string& nodeName) {
    if (nodeName.find("Layout") != std::string::npos) {
        return true;
    }

    return false;
}

} // namespace ui
} // namespace vex
