#ifndef WASM_DOM_SHADOWROOTINIT_H_
#define WASM_DOM_SHADOWROOTINIT_H_

#include "shadowrootmode.hpp"
#include "../_basic.hpp"

namespace dom {

struct ShadowRootInit {
  ShadowRootMode mode;
};

} // namespace dom
#endif // WASM_DOM_SHADOWROOTINIT_H_