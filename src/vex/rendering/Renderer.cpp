/**
 * @file Renderer.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Renderer.h"

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include "WindowManager.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace rendering {

bool Renderer::initialize() {
    bgfx::renderFrame();

    bgfx::Init init;
    init.platformData.nwh = rendering::WindowManager::getInstance().getDefaultWindow()->getNativeHandle();
    init.platformData.ndt = rendering::WindowManager::getInstance().getNativeDisplayHandle();
    init.resolution.width = 600;
    init.resolution.height = 600;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);

    const bgfx::Caps* caps = bgfx::getCaps();
    bool swapChainSupported = 0 != (caps->supported & BGFX_CAPS_SWAP_CHAIN);
    LOG_TRACE("{0}", swapChainSupported);

    return true;
}

void Renderer::shutdown() {
    bgfx::shutdown();
}

void Renderer::commit() {
    bgfx::frame(false);
}

Renderer& Renderer::getInstance() {
    static Renderer renderer;
    return renderer;
}

} // namespace rendering
} // namespace vex