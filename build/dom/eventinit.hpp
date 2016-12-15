#pragma once
#include "../_basic.hpp"

namespace dom {

struct EventInit {
  bool bubbles = false;
  bool cancelable = false;
  bool composed = false;
};

} // namespace dom
