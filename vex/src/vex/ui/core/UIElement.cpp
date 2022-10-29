/**
 * @file UIElement.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "UIElement.h"

namespace vex {
namespace ui {

void UIElement::setSize(const glm::vec2& size) {
    p_size = size;
}

const glm::vec2 UIElement::getSize() const {
    return p_size;
}

void UIElement::setParent(UIElement* parent) {
    p_parent = parent;
}

void UIElement::setPosition(const glm::vec2& position) {
    p_position = position;
}

const glm::vec2 UIElement::getPosition() const {
    return p_position;
}

} // namespace ui
} // namespace vex