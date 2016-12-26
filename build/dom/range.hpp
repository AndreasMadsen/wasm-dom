#ifndef WASM_DOM_RANGE_H_
#define WASM_DOM_RANGE_H_

#include "node.hpp"
#include "short.hpp"
#include "documentfragment.hpp"
#include "../_basic.hpp"

namespace dom {

class Range {
  public:
    // constants
    static const unsigned short START_TO_START = 0;
    static const unsigned short START_TO_END = 1;
    static const unsigned short END_TO_END = 2;
    static const unsigned short END_TO_START = 3;

    // attributes
    Node get_startContainer() const;
    unsigned long get_startOffset() const;
    Node get_endContainer() const;
    unsigned long get_endOffset() const;
    bool get_collapsed() const;
    Node get_commonAncestorContainer() const;

    // methods
    const void setStart(const Node node, const unsigned long offset);
    const void setEnd(const Node node, const unsigned long offset);
    const void setStartBefore(const Node node);
    const void setStartAfter(const Node node);
    const void setEndBefore(const Node node);
    const void setEndAfter(const Node node);
    const void collapse(const optional<bool> toStart = false);
    const void selectNode(const Node node);
    const void selectNodeContents(const Node node);
    const short compareBoundaryPoints(const unsigned short how, const Range sourceRange);
    const void deleteContents();
    const DocumentFragment extractContents();
    const DocumentFragment cloneContents();
    const void insertNode(const Node node);
    const void surroundContents(const Node newParent);
    const Range cloneRange();
    const void detach();
    const bool isPointInRange(const Node node, const unsigned long offset);
    const short comparePoint(const Node node, const unsigned long offset);
    const bool intersectsNode(const Node node);
};

} // namespace dom
#endif // WASM_DOM_RANGE_H_