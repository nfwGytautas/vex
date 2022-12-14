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
     * @param out Color object to store result in
     * @return true if colorString is valid, false otherwise
     */
    static bool fromString(const char* colorString, Color& out);
};

} // namespace ui
} // namespace vex
