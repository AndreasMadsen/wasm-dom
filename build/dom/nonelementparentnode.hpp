#pragma once
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class NonElementParentNode {
  public:
    // methods
    const optional<Element> getElementById(const std::string elementId);
};

} // namespace dom
