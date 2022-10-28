/**
 * @file WindowParsingFunction.h
 * @author nfwGytautas
 * @date 10/29/22
 */

#pragma once

#include "vex/ui/parsing/IParsingFunction.h"

namespace vex {
namespace ui {
namespace parsers {

/**
 * @brief Window node parser function
 */
class WindowParsingFunction final : IParsingFunction {
public:
    WindowParsingFunction() = default;
    ~WindowParsingFunction() = default;

    /**
     * Returns the instance of the parsing function
     */
    static IParsingFunction* getInstance();

    bool canParse(const std::string& nodeName) override;
    bool parse(const pugi::xml_node& node, UIElement*& out) override;

private:
};

} // namespace parsers
} // namespace ui
} // namespace vex
