/**
 * @file Window.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>

#include <glm/glm.hpp>

#include "vex/rendering/GfxWindow.h"
#include "vex/ui/common/Color.h"

namespace vex {
namespace ui {

/**
 * @brief Window is used to define a GUI window
 */
class Window final {
public:
    Window() = default;
    ~Window() = default;

    /**
     * Sets the title of the window
     * @param title Title of the window
     */
    void setTitle(const std::string& title);

    /**
     * Renders the contents of this window
     */
    void render();

    /**
     * Set the background color of the window
     * @param color Color of the window background
     */
    void setBackgroundColor(vex::ui::Color color);

    /**
     * Sets the GfxWindow instance for this window
     * @param window Window instance
     */
    void setGfxWindow(rendering::GfxWindow* window);

    /**
     * Set the size of the window
     * @param size new size of the window
     */
    void setSize(const glm::vec2& size);

private:
    /**
     * Updates the data of the GfxWindow
     */
    void updateGfxWindowData();

private:
    rendering::GfxWindow* m_gfx = nullptr;
    bool m_requiresDataUpdate = false;

    std::string m_title;
    ui::Color m_bgColor {};
    glm::vec2 m_size {50, 50};
};

} // namespace ui
} // namespace vex
