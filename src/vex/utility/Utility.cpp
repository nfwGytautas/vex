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
    result.push_back(str.substr(last));

    return result;
}

} // namespace utility
} // namespace vex