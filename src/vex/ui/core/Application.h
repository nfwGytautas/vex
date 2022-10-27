/**
 * @file Application.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <vector>

#include "Window.h"

namespace vex {
namespace ui {

/**
 * @brief Application is the main class for vex UI
 */
class Application final {
public:
    Application() = default;
    ~Application();

    /**
     * Add a window to the application
     * @param pWindow Window pointer
     */
    void addWindow(vex::ui::Window* pWindow);

private:
    std::vector<Window*> m_windows;
};

} // namespace ui
} // namespace vex
