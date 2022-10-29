/**
 * @file Utility.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

namespace vex {
namespace utility {

/**
 * @brief Utility functions for vex
 */
class Utility final {
public:
    Utility() = default;
    ~Utility() = default;

    /**
     * Split string by the delimiter
     * @param str Input string
     * @param delim delimiter
     * @return Array of values split from the string
     */
    static std::vector<std::string> stringSplit(const std::string& str, const char delim);

    /**
     * Returns true if the passed string contains any data that isn't only whitespaces, false otherwise
     */
    static bool stringIsNotEmpty(const std::string& str);

    /**
     * Parses the string into the vector
     * @param str String to parse
     * @param out Vec to store result in
     * @return true if parsed, false otherwise
     */
    static bool stringToVec2(const std::string& str, glm::vec2& out);
};

} // namespace utility
} // namespace vex
