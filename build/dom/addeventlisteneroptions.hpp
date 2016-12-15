#pragma once
#include "eventlisteneroptions.hpp"
#include "../_basic.hpp"

namespace dom {

struct AddEventListenerOptions : EventListenerOptions {
  bool passive = false;
  bool once = false;
};

} // namespace dom
