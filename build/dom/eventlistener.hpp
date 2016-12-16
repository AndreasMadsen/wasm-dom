#pragma once
#include "event.hpp"
#include "../_basic.hpp"

namespace dom {

class EventListener {
  public:
    // methods
    const void handleEvent(const Event event);
};

} // namespace dom
