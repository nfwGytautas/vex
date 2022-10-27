/**
 * @file Renderer.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

namespace vex {
namespace rendering {

/**
 * @brief Vex renderer
 */
class Renderer final {
public:
    Renderer() = default;
    ~Renderer() = default;

    /**
     * Get singleton instance
     * @return Renderer singleton instance
     */
    static Renderer& getInstance();

    /**
     * Initializes the renderer
     * @return true if initialized, false otherwise
     */
    bool initialize();

    /**
     * Shutdown the window renderer
     */
    void shutdown();

    /**
     * Commit render commands to GPU
     */
    void commit();

private:
};

} // namespace rendering
} // namespace vex
