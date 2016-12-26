#ifndef WASM_DOM_EVENTTARGET_H_
#define WASM_DOM_EVENTTARGET_H_

#include "eventlistener.hpp"
#include "addeventlisteneroptions.hpp"
#include "eventlisteneroptions.hpp"
#include "event.hpp"
#include "../_basic.hpp"

namespace dom {

class EventTarget {
  public:
    // methods
    const void addEventListener(const std::string type, const nullable<EventListener> callback, const optional<multiple<AddEventListenerOptions, bool>> options);
    const void removeEventListener(const std::string type, const nullable<EventListener> callback, const optional<multiple<EventListenerOptions, bool>> options);
    const bool dispatchEvent(const Event event);
};

} // namespace dom
#endif // WASM_DOM_EVENTTARGET_H_