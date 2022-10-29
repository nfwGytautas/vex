/**
 * @file FunctionTypes.h
 * @author nfwGytautas
 * @date 10/29/22
 */

#pragma once

namespace vex {
namespace ui {
namespace elements {
class Button;
}
} // namespace ui
} // namespace vex

namespace vex {
namespace binding {

typedef void (*ButtonOnClick)(vex::ui::elements::Button*);

}
} // namespace vex
