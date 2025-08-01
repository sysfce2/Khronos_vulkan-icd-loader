/*
 * Copyright (c) 2022 The Khronos Group Inc.
 * Copyright (c) 2022 Valve Corporation
 * Copyright (c) 2022 LunarG, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and/or associated documentation files (the "Materials"), to
 * deal in the Materials without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Materials, and to permit persons to whom the Materials are
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice(s) and this permission notice shall be included in
 * all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE
 * USE OR OTHER DEALINGS IN THE MATERIALS.
 *
 * Author: Charles Giessen <charles@lunarg.com>
 */

#include <iostream>
#include <string>

#include "util/test_defines.h"
#include "util/functions.h"
#include "util/dynamic_library_wrapper.h"

extern "C" {

using DoLogicFunction = char (*)();
#define DO_LOGIC_FUNCTION_NAME "do_logic"
FRAMEWORK_EXPORT char do_logic();

using InitFunction = void (*)();
#define INIT_FUNCTION_NAME "init"
FRAMEWORK_EXPORT void init();
};

#if defined(_WIN32)
#if !defined(LIB_EXT)
#define LIB_EXT "dll"
#endif
#elif defined(__APPLE__)
#if !defined(LIB_EXT)
#define LIB_EXT "dylib"
#endif
#else
#if !defined(LIB_EXT)
#define LIB_EXT "so"
#endif
#endif
