/**
 * @file CodeLoader.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include "CodeLoader.h"
#include <filesystem>

#include <dlfcn.h>

#include "vex/utility/Logger.h"

namespace vex {
namespace binding {

CodeLoader& CodeLoader::getInstance() {
    static CodeLoader instance;
    return instance;
}

bool CodeLoader::load() {
    auto codePath = (m_projectRoot / "libapp.so");

    if (m_code != nullptr) {
        if (dlclose(m_code)) {
            LOG_ERROR("[Code loader] Failed closing code {0}", dlerror());
        }
        m_code = nullptr;
    }

    m_code = dlopen(codePath.string().c_str(), RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND);

    if (m_code == nullptr) {
        LOG_ERROR("[Code loader] Failed loading code {0}", dlerror());
        return false;
    }

    return true;
}

ButtonOnClick CodeLoader::getButtonOnClickFunction(const char* functionName) {
    if (m_code == nullptr) {
        return nullptr;
    }

    return (ButtonOnClick)dlsym(m_code, functionName);
}

void CodeLoader::setProjectRoot(const std::filesystem::path& root) {
    m_projectRoot = root;
}

} // namespace binding
} // namespace vex