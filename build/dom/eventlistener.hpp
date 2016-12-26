#ifndef WASM_DOM_EVENTLISTENER_H_
#define WASM_DOM_EVENTLISTENER_H_

#include "event.hpp"
#include "../_basic.hpp"

namespace dom {

class EventListener {
  public:
    // methods
    const void handleEvent(const Event event);
};

} // namespace dom
#endif // WASM_DOM_EVENTLISTENER_H_