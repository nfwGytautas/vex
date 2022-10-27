/**
 * @file Color.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Color.h"
#include <string>

#include "vex/utility/Logger.h"
#include "vex/utility/Utility.h"

namespace vex {
namespace ui {

Color Color::fromString(const char* colorString) {
    Color c {};

    std::string color(colorString);

    if (color.substr(0, 3) == "RGB") {
        auto values = utility::Utility::stringSplit(color.substr(4, color.length() - 5), ',');

        c.R = std::stof(values[0]) / 255.0f;
        c.G = std::stof(values[1]) / 255.0f;
        c.B = std::stof(values[2]) / 255.0f;
        c.A = 1.0f;
    }

    return c;
}

} // namespace ui
} // namespace vex
