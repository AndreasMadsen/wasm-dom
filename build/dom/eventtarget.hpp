#pragma once
#include "eventlistener.hpp"
#include "addeventlisteneroptions.hpp"
#include "eventlisteneroptions.hpp"
#include "event.hpp"
#include "../_basic.hpp"

namespace dom {

class EventTarget {
  public:
    // methods
    const void addEventListener(const std::string type, const optional<EventListener> callback, const union<AddEventListenerOptions, bool> options);
    const void removeEventListener(const std::string type, const optional<EventListener> callback, const union<EventListenerOptions, bool> options);
    const bool dispatchEvent(const Event event);
};

} // namespace dom
