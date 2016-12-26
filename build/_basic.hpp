#pragma once
#include <string>
#include <vector>
#include <emscripten/val.h>

namespace dom {

// === TEMP ===
template<typename T>
class optional;
template<typename T>
class nullable;
template<typename T, typename ...Ts>
class multiple;
typedef emscripten::val any;
// === TEMP ===

}