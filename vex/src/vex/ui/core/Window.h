/**
 * @file Window.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>

#include <glm/glm.hpp>

#include "UIElement.h"
#include "vex/rendering/GfxWindow.h"
#include "vex/ui/common/Color.h"

namespace vex {
namespace ui {

/**
 * @brief Window is used to define a GUI window
 */
class Window final : public UIElement {
public:
    Window() = default;
    ~Window() override;

    /**
     * Sets the title of the window
     * @param title Title of the window
     */
    void setTitle(const std::string& title);

    void update() override;

    /**
     * Renders the contents of this window
     */
    void render() override;

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
     * Set the layout of the window
     * @param layout new layout instance
     */
    void setLayout(UIElement* layout);

private:
    rendering::GfxWindow* m_gfx = nullptr;

    std::string m_title;
    ui::Color m_bgColor {};

    ui::UIElement* m_layout = nullptr;
};

} // namespace ui
} // namespace vex
