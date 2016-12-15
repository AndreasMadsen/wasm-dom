#pragma once
#include "eventinit.hpp"
#include "any.hpp"
#include "../_basic.hpp"

namespace dom {

struct CustomEventInit : EventInit {
  any detail = NULL;
};

} // namespace dom
