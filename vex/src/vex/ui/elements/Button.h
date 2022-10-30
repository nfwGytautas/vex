/**
 * @file Button.h
 * @author nfwGytautas
 * @date 10/28/22
 */

#pragma once

#include "vex/binding/FunctionTypes.h"
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

    void setOnClick(binding::ButtonOnClick callback);

private:
    binding::ButtonOnClick m_onClick = nullptr;

    // TODO: testing
    void generate();
    unsigned int VBO, VAO, EBO;
    bool generated = false;
};

} // namespace elements
} // namespace ui
} // namespace vex
