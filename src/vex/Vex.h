/**
 * @file Vex.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#include <filesystem>

#include "vex/ui/core/Application.h"

namespace vex {

/**
 * @brief The entry point class for Vex
 */
class Vex final {
public:
    Vex() = default;
    ~Vex() = default;

    /**
     * Entry point for vex, pass cmd arguments to the function
     * @param argc Number of console arguments
     * @param argv Argument values
     * @return Error code
     */
    int start(int argc, char** argv);

private:
    /**
     * Parse console arguments
     * @param argc Number of console arguments
     * @param argv Argument values
     * @return true if arguments are valid, false otherwise
     */
    bool parseCmdArguments(int argc, char** argv);

private:
    std::filesystem::path m_projectRoot;
    ui::Application* m_app = nullptr;
};

} // namespace vex
