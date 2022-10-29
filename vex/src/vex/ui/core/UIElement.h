/**
 * @file UIElement.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <glm/glm.hpp>

namespace vex {
namespace ui {

/**
 * @brief Base class for UI elements
 */
class UIElement {
public:
    UIElement() = default;
    virtual ~UIElement() = default;

    /**
     * Update the state of the element
     */
    virtual void update() = 0;

    /**
     * Render the element
     */
    virtual void render() = 0;

    /**
     * Set the size of the UI element
     * @param size new size of the element
     */
    void setSize(const glm::vec2& size);

    /**
     * Get the size of the UI element
     * @return size of the element
     */
    const glm::vec2 getSize() const;

    /**
     * Set the position of the UI element
     * @param size new position of the element
     */
    void setPosition(const glm::vec2& position);

    /**
     * Get the position of the UI element
     * @return position of the element
     */
    const glm::vec2 getPosition() const;

    /**
     * Sets the parent of the UI element
     * @param parent new parent of the element
     */
    void setParent(UIElement* parent);

protected:
    UIElement* p_parent = nullptr;

    glm::vec2 p_size {0, 0};
    glm::vec2 p_position {0, 0};

private:
};

} // namespace ui
} // namespace vex
