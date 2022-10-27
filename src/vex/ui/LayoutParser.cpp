/**
 * @file LayoutParser.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "LayoutParser.h"
#include <utility>

#include <pugixml/pugixml.hpp>

#include "vex/Macros.h"
#include "vex/ui/common/Color.h"
#include "vex/utility/Logger.h"

namespace vex {

LayoutParser::LayoutParser(std::filesystem::path projectRoot) : m_root(std::move(projectRoot)) {}

bool LayoutParser::parse(ui::Application* pApplication) {
    // Create application object
    m_app = pApplication;

    if (!parseXmlFile(m_root / "Init.xml")) {
        onFail();
    }

    return true;
}

void LayoutParser::onFail() {
    delete m_app;
}
bool LayoutParser::parseXmlFile(const std::filesystem::path& file) {
    LOG_TRACE("[LAYOUT PARSER] Parsing: {0}", file.c_str());

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

    if (!title.empty()) {
        window->setTitle(title.value());
    }

    if (!bgColor.empty()) {
        window->setBackgroundColor(ui::Color::fromString(bgColor.value()));
    }

    return window;
}

} // namespace vex