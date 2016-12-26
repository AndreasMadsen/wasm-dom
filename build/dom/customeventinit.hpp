#ifndef WASM_DOM_CUSTOMEVENTINIT_H_
#define WASM_DOM_CUSTOMEVENTINIT_H_

#include "eventinit.hpp"
#include "../_basic.hpp"

namespace dom {

struct CustomEventInit : EventInit {
  any detail = NULL;
};

} // namespace dom
#endif // WASM_DOM_CUSTOMEVENTINIT_H_