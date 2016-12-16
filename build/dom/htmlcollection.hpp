#pragma once
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class HTMLCollection {
  public:
    // attributes
    unsigned long get_length() const;

    // methods
    const optional<Element> item(const unsigned long index);
    const optional<Element> namedItem(const std::string name);
};

} // namespace dom
