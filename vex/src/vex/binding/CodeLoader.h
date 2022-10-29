/**
 * @file CodeLoader.h
 * @author nfwGytautas
 * @date 10/29/22
 */

#pragma once

#include <filesystem>

#include "vex/binding/FunctionTypes.h"

namespace vex {
namespace binding {

/**
 * @brief Class used for loading lib files that contain app code
 */
class CodeLoader final {
public:
    CodeLoader() = default;
    ~CodeLoader() = default;

    /**
     * Get singleton instance
     * @return CodeLoader singleton instance
     */
    static CodeLoader& getInstance();

    bool load();

    ButtonOnClick getButtonOnClickFunction(const char* functionName);

    void setProjectRoot(const std::filesystem::path& root);

private:
    std::filesystem::path m_projectRoot;
    void* m_code = nullptr;
};

} // namespace binding
} // namespace vex
