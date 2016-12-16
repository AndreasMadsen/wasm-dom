#pragma once
#include "event.hpp"
#include "any.hpp"
#include "../_basic.hpp"

namespace dom {

class CustomEvent : Event {
  public:
    // attributes
    any get_detail() const;

    // methods
    const void initCustomEvent(const std::string type, const bool bubbles, const bool cancelable, const any detail);
};

} // namespace dom
