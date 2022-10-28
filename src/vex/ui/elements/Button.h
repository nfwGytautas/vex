/**
 * @file Button.h
 * @author nfwGytautas
 * @date 10/28/22
 */

#pragma once

#include "vex/ui/core/UIElement.h"

namespace vex {
namespace ui {
namespace elements {

/**
 * @brief Button element implementation
 */
class Button final : public UIElement {
public:
    Button() = default;
    ~Button();

    void update() override;
    void render() override;

private:
};

} // namespace elements
} // namespace ui
} // namespace vex
