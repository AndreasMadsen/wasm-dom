#ifndef WASM_DOM_CUSTOMEVENT_H_
#define WASM_DOM_CUSTOMEVENT_H_

#include "event.hpp"
#include "../_basic.hpp"

namespace dom {

class CustomEvent : public Event {
  public:
    // attributes
    any get_detail() const;

    // methods
    const void initCustomEvent(const std::string type, const bool bubbles, const bool cancelable, const any detail);
};

} // namespace dom
#endif // WASM_DOM_CUSTOMEVENT_H_