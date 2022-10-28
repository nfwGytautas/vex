/**
 * @file LayoutParser.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "LayoutParser.h"
#include <utility>

#include <pugixml/pugixml.hpp>

#include "glm/vec2.hpp"
#include "vex/Macros.h"
#include "vex/ui/common/Color.h"
#include "vex/utility/Logger.h"
#include "vex/utility/Utility.h"

namespace vex {

LayoutParser::LayoutParser(std::filesystem::path projectRoot) : m_root(std::move(projectRoot)) {}

bool LayoutParser::parse(ui::Application* pApplication) {
    // Create application object
    m_app = pApplication;

    if (!parseXmlFile(m_root / "Init.xml")) {
        return false;
    }

    return true;
}

bool LayoutParser::parseXmlFile(const std::filesystem::path& file) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file.c_str());

    if (result) {
        for (const pugi::xml_node& child : doc.children()) {
            const std::string nodeName = std::string(child.name());
            if (nodeName == "Application") {
                // Application node
                if (!parseApplicationNode(child)) {
                    return false;
                }
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

bool LayoutParser::parseApplicationNode(const LayoutParser::XmlNode& node) {
    // Windows
    for (const pugi::xml_node& window : node.child("Windows").children()) {
        ui::Window* pWindow = parseWindowNode(window);
        m_app->addWindow(pWindow);
    }

    return true;
}

ui::Window* LayoutParser::parseWindowNode(const LayoutParser::XmlNode& node) {
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
    }

    return window;
}

} // namespace vex