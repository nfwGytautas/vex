/**
 * @file LayoutBase.h
 * @author nfwGytautas
 * @date 10/28/22
 */

#pragma once

#include <vector>

#include "vex/ui/core/UIElement.h"

namespace vex {
namespace ui {
namespace layout {

/**
 * @brief Base class for all layouts
 */
class LayoutBase : public UIElement {
public:
    LayoutBase() = default;
    ~LayoutBase() override;

    void update() override;
    void render() override;

    /**
     * Add element to layout
     * @param element Element object
     */
    void addElement(UIElement* element);

protected:
    std::vector<UIElement*> p_elements;

private:
};

} // namespace layout
} // namespace ui
} // namespace vex
