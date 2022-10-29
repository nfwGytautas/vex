/**
 * @file Macros.h
 * @author nfwGytautas
 * @date 10/27/22
 */

#pragma once

#ifdef _DEBUG
#include <cassert>
#define VEX_DEBUG_SECTION(code)            code
#define VEX_STATIC_ASSERT(check, message)  static_assert(check, message)
#define VEX_DYNAMIC_ASSERT(check, message) assert(((void)message, check))
#define VEX_ABORT(message)                 assert(((void)message, false))
#else
#include "vex/utility/Logger.h"
#define VEX_DEBUG_SECTION(code)
#define VEX_STATIC_ASSERT(check, message)
#define VEX_DYNAMIC_ASSERT(check, message)                                                          \
    if (!check) {                                                                                   \
        LOG_ERROR("Failed check {0}, in {1} at line {2}, {3}", #check, __FILE__, __LINE__, message) \
    };
#define VEX_ABORT(message)
#endif
