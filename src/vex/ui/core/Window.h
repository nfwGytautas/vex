/**
 * @file Window.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>

#include "vex/rendering/GfxWindow.h"

namespace vex {
namespace ui {

/**
 * @brief Window is used to define a GUI window
 */
class Window final : public rendering::GfxWindow {
public:
    Window() = default;
    ~Window() = default;

    /**
     * Create the window
     */
    void create() override;

    /**
     * Sets the title of the window
     * @param title Title of the window
     */
    void setTitle(const std::string& title);

    /**
     * Renders the contents of this window
     */
    void render();

private:
    std::string m_title;
};

} // namespace ui
} // namespace vex
