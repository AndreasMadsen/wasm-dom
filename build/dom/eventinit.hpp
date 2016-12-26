#ifndef WASM_DOM_EVENTINIT_H_
#define WASM_DOM_EVENTINIT_H_

#include "../_basic.hpp"

namespace dom {

struct EventInit {
  bool bubbles = false;
  bool cancelable = false;
  bool composed = false;
};

} // namespace dom
#endif // WASM_DOM_EVENTINIT_H_
