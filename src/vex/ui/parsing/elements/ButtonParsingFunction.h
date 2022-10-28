/**
 * @file ButtonParsingFunction.h
 * @author nfwGytautas
 * @date 10/29/22
 */

#pragma once

#include "vex/ui/parsing/IParsingFunction.h"

namespace vex {
namespace ui {
namespace parsers {

/**
 * @brief Button node parsing function
 */
class ButtonParsingFunction final : public IParsingFunction {
public:
    ButtonParsingFunction() = default;
    ~ButtonParsingFunction() = default;

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
