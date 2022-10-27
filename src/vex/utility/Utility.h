/**
 * @file Utility.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <string>
#include <vector>

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
};

} // namespace utility
} // namespace vex
