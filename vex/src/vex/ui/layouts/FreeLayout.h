/**
 * @file FreeLayout.h
 * @author nfwGytautas
 * @date 10/28/22
 */

#pragma once

#include "vex/ui/layouts/LayoutBase.h"

namespace vex {
namespace ui {
namespace layout {

/**
 * @brief Free layout implementation
 */
class FreeLayout final : public LayoutBase {
public:
    FreeLayout() = default;
    ~FreeLayout() override = default;

    void update() override;
    void render() override;

private:
};

} // namespace layout
} // namespace ui
} // namespace vex
