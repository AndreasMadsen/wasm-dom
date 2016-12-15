#pragma once
#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class ChildNode {
  // methods
  const void before(const union<Node, std::string> nodes);
  const void after(const union<Node, std::string> nodes);
  const void replaceWith(const union<Node, std::string> nodes);
  const void remove();
};

} // namespace dom
