#ifndef WASM_DOM_TREEWALKER_H_
#define WASM_DOM_TREEWALKER_H_

#include "node.hpp"
#include "nodefilter.hpp"
#include "../_basic.hpp"

namespace dom {

class TreeWalker {
  public:
    // attributes
    Node get_root() const;
    unsigned long get_whatToShow() const;
    nullable<NodeFilter> get_filter() const;
    Node get_currentNode() const;
    Node set_currentNode(const Node currentNode);

    // methods
    const nullable<Node> parentNode();
    const nullable<Node> firstChild();
    const nullable<Node> lastChild();
    const nullable<Node> previousSibling();
    const nullable<Node> nextSibling();
    const nullable<Node> previousNode();
    const nullable<Node> nextNode();
};

} // namespace dom
#endif // WASM_DOM_TREEWALKER_H_