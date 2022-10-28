/**
 * @file LayoutParser.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "LayoutParser.h"
#include <utility>

#include "pugixml/pugixml.hpp"
#include "vex/Macros.h"
#include "vex/ui/parsing/IParsingFunction.h"
#include "vex/utility/Logger.h"

namespace vex {

LayoutParser::LayoutParser(std::filesystem::path projectRoot) : m_root(std::move(projectRoot)) {}

bool LayoutParser::parse(ui::Application*& pApplication) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((m_root / "Init.xml").c_str());

    ui::IParsingFunction* applicationParser = ui::IParsingFunction::getParser("Application");
    VEX_DYNAMIC_ASSERT(applicationParser != nullptr, "Application parser not defined");

    if (result) {
        for (const pugi::xml_node& child : doc.children()) {
            if (std::string("Application") != child.name()) {
                LOG_ERROR("Root node needs to be Application");
                return false;
            }

            if (!applicationParser->parse(child, reinterpret_cast<ui::UIElement*&>(pApplication))) {
                return false;
            }
        }
    } else {
        LOG_ERROR("XML parsing failed with errors");
        LOG_ERROR("Error description: {0}", result.description());

        // TODO: Source location error
        // LOG_ERROR("Error offset: {0}" << result.offset << " (error at [..." << (source + result.offset) << "]\n\n";

        return false;
    }

    return true;
}

} // namespace vex