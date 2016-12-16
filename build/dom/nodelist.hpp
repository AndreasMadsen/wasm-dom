#pragma once
#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class NodeList {
  public:
    // attributes
    unsigned long get_length() const;

    // methods
    const optional<Node> item(const unsigned long index);
};

} // namespace dom
