#pragma once
#include "node.hpp"
#include "nodefilter.hpp"
#include "../_basic.hpp"

namespace dom {

class TreeWalker {
  public:
    // attributes
    Node get_root() const;
    unsigned long get_whatToShow() const;
    optional<NodeFilter> get_filter() const;
    Node get_currentNode() const;
    Node set_currentNode(const Node currentNode);

    // methods
    const optional<Node> parentNode();
    const optional<Node> firstChild();
    const optional<Node> lastChild();
    const optional<Node> previousSibling();
    const optional<Node> nextSibling();
    const optional<Node> previousNode();
    const optional<Node> nextNode();
};

} // namespace dom
