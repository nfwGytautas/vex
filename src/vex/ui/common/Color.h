/**
 * @file Color.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

namespace vex {
namespace ui {

/**
 * Struct for denoting a color
 */
struct Color {
    float R;
    float G;
    float B;
    float A;

    /**
     * Parses a color from a string value
     * @param colorString String value
     * @return Color data struct
     */
    static Color fromString(const char* colorString);
};

} // namespace ui
} // namespace vex
