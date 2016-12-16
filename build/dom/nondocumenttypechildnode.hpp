#pragma once
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class NonDocumentTypeChildNode {
  public:
    // attributes
    optional<Element> get_previousElementSibling() const;
    optional<Element> get_nextElementSibling() const;
};

} // namespace dom
