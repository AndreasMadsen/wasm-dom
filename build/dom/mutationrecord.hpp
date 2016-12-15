#pragma once
#include "node.hpp"
#include "nodelist.hpp"
#include "../_basic.hpp"

namespace dom {

class MutationRecord {
  // attributes
  std::string get_type() const;
  Node get_target() const;
  NodeList get_addedNodes() const;
  NodeList get_removedNodes() const;
  optional<Node> get_previousSibling() const;
  optional<Node> get_nextSibling() const;
  optional<std::string> get_attributeName() const;
  optional<std::string> get_attributeNamespace() const;
  optional<std::string> get_oldValue() const;
};

} // namespace dom
