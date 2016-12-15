#pragma once
#include "htmlcollection.hpp"
#include "element.hpp"
#include "node.hpp"
#include "nodelist.hpp"
#include "../_basic.hpp"

namespace dom {

class ParentNode {
  // attributes
  HTMLCollection get_children() const;
  optional<Element> get_firstElementChild() const;
  optional<Element> get_lastElementChild() const;
  unsigned long get_childElementCount() const;

  // methods
  const void prepend(const union<Node, std::string> nodes);
  const void append(const union<Node, std::string> nodes);
  const optional<Element> querySelector(const std::string selectors);
  const NodeList querySelectorAll(const std::string selectors);
};

} // namespace dom
