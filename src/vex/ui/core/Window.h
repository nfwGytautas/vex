/**
 * @file Window.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>

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

private:
    std::string m_title;
};

} // namespace ui
} // namespace vex
