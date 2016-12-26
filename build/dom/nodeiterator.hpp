#ifndef WASM_DOM_NODEITERATOR_H_
#define WASM_DOM_NODEITERATOR_H_

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
    nullable<NodeFilter> get_filter() const;

    // methods
    const nullable<Node> nextNode();
    const nullable<Node> previousNode();
    const void detach();
};

} // namespace dom
#endif // WASM_DOM_NODEITERATOR_H_
