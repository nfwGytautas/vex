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

bool Color::fromString(const char* colorString, Color& out) {
    out = {};
    std::string color(colorString);

    if (color.substr(0, 3) == "RGB") {
        auto values = utility::Utility::stringSplit(color.substr(4, color.length() - 5), ',');

        if (values.size() != 3) {
            return false;
        }

        out.R = std::stof(values[0]) / 255.0f;
        out.G = std::stof(values[1]) / 255.0f;
        out.B = std::stof(values[2]) / 255.0f;
        out.A = 1.0f;
    }

    return true;
}

} // namespace ui
} // namespace vex
