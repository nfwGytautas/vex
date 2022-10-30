/**
 * @file LayoutBase.cpp
 * @author nfwGytautas
 * @date 10/28/22
 */

#include "LayoutBase.h"

namespace vex {
namespace ui {
namespace layout {

LayoutBase::~LayoutBase() noexcept {
    for (UIElement* element : p_elements) {
        delete element;
    }
}

void LayoutBase::update() {
    p_size = p_parent->getSize();

    for (UIElement* element : p_elements) {
        element->update();
    }
}

void LayoutBase::render() {
    for (UIElement* element : p_elements) {
        element->render();
    }
}

void LayoutBase::addElement(UIElement* element) {
    p_elements.push_back(element);
}

} // namespace layout
} // namespace ui
} // namespace vex