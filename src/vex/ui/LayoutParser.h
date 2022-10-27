/**
 * @file LayoutParser.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <filesystem>

#include "pugixml/pugixml.hpp"
#include "vex/ui/core/Application.h"
#include "vex/ui/core/Window.h"

namespace vex {

/**
 * @brief The class used to parse vex ui files and provide ui for it
 */
class LayoutParser final {
    using XmlNode = pugi::xml_node;

public:
    /**
     * Create a ui parser for the specified project root
     * @param projectRoot Project root directory
     */
    explicit LayoutParser(std::filesystem::path projectRoot);

    /**
     * Parse the Init.xml file in project root and fill in the application object
     * @param pApplication nullptr application object to store information in
     * @return true if parsed without errors, false otherwise
     */
    bool parse(vex::ui::Application*& pApplication);

private:
    /**
     * Method invoked any time something failed (FATAL) in ui parsing
     */
    void onFail();

    /**
     * Parses an xml file specified by the file parameter
     * @param file File to parse
     * @return True if the file has been parsed without errors, false otherwise
     */
    bool parseXmlFile(const std::filesystem::path& file);

    /**
     * Parses a <Application> node
     * @param node Node to pasre
     * @return True if the node has been parsed without error, false otherwise
     */
    bool parseApplicationNode(const XmlNode& node);

    /**
     * Parses a <Window> node
     * @param node Node to parse
     * @return Window object or nullptr if something failed
     */
    ui::Window* parseWindowNode(const XmlNode& node);

private:
    std::filesystem::path m_root;
    ui::Application* m_app = nullptr;
};

} // namespace vex
