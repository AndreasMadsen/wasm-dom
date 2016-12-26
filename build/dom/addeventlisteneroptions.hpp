#ifndef WASM_DOM_ADDEVENTLISTENEROPTIONS_H_
#define WASM_DOM_ADDEVENTLISTENEROPTIONS_H_

#include "eventlisteneroptions.hpp"
#include "../_basic.hpp"

namespace dom {

struct AddEventListenerOptions : EventListenerOptions {
  bool passive = false;
  bool once = false;
};

} // namespace dom
#endif // WASM_DOM_ADDEVENTLISTENEROPTIONS_H_