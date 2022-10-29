/**
 * @file ParsingFunction.h
 * @author nfwGytautas
 * @date 10/28/22
 */

#pragma once

#include <string>

#include <pugixml/pugixml.hpp>

#include "vex/ui/core/UIElement.h"

namespace vex {
namespace ui {

/**
 * @brief Parsing function interface
 */
class IParsingFunction {
public:
    virtual ~IParsingFunction() = default;

    /**
     * Returns true if the function can parse the specified node name, false otherwise
     * @param nodeName Name of the node to parse
     */
    virtual bool canParse(const std::string& nodeName) = 0;

    /**
     * Parses xml node and stores result in out parameter
     * @param node Node to parse
     * @param out Object to store result in (must be nullptr)
     * @return true if parsed correctly, false otherwise
     */
    virtual bool parse(const pugi::xml_node& node, UIElement*& out) = 0;

    /**
     * Returns the parser for the specified node name, nullptr if parsing function is not defined
     * @param nodeName XML node name
     * @return Parsing function instance
     */
    static IParsingFunction* getParser(const std::string& nodeName);

    /**
     * Returns true if the specified node name is of layout type, false otherwise
     */
    static bool isLayoutNode(const std::string& nodeName);
};

} // namespace ui
} // namespace vex
