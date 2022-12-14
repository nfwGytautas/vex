/**
 * @file Utility.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Utility.h"

namespace vex {
namespace utility {

std::vector<std::string> Utility::stringSplit(const std::string& str, const char delim) {
    std::vector<std::string> result;

    // 3 Component
    size_t last = 0;
    size_t next = 0;

    while ((next = str.find(delim, last)) != std::string::npos) {
        result.push_back(str.substr(last, next - last));
        last = next + 1;
    }

    if (stringIsNotEmpty(str.substr(last))) {
        result.push_back(str.substr(last));
    }

    return result;
}

bool Utility::stringIsNotEmpty(const std::string& str) {
    return str.find_first_not_of(' ') != str.npos;
}

bool Utility::stringToVec2(const std::string& str, glm::vec2& out) {
    if (str[0] != '(') {
        return false;
    }

    if (str[str.length() - 1] != ')') {
        return false;
    }

    auto values = stringSplit(str.substr(1, str.length() - 2), ',');

    out.x = std::stof(values[0]);
    out.y = std::stof(values[1]);

    return true;
}

} // namespace utility
} // namespace vex