#pragma once
#include "node.hpp"
#include "nodefilter.hpp"
#include "../_basic.hpp"

namespace dom {

class NodeIterator {
  public:
    // attributes
    Node get_root() const;
    Node get_referenceNode() const;
    bool get_pointerBeforeReferenceNode() const;
    unsigned long get_whatToShow() const;
    optional<NodeFilter> get_filter() const;

    // methods
    const optional<Node> nextNode();
    const optional<Node> previousNode();
    const void detach();
};

} // namespace dom
