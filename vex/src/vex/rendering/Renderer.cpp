/**
 * @file Renderer.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "Renderer.h"

#include "WindowManager.h"
#include "vex/utility/Logger.h"

namespace vex {
namespace rendering {

bool Renderer::initialize() {


    return true;
}

void Renderer::shutdown() {}

void Renderer::commit() {}

Renderer& Renderer::getInstance() {
    static Renderer renderer;
    return renderer;
}

} // namespace rendering
} // namespace vex