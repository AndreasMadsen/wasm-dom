#ifndef WASM_DOM_PARENTNODE_H_
#define WASM_DOM_PARENTNODE_H_

#include "htmlcollection.hpp"
#include "element.hpp"
#include "node.hpp"
#include "nodelist.hpp"
#include "../_basic.hpp"

namespace dom {

class ParentNode {
  public:
    // attributes
    HTMLCollection get_children() const;
    nullable<Element> get_firstElementChild() const;
    nullable<Element> get_lastElementChild() const;
    unsigned long get_childElementCount() const;

    // methods
    const void prepend(const Node nodes);
    const void prepend(const std::string nodes);
    const void append(const Node nodes);
    const void append(const std::string nodes);
    const nullable<Element> querySelector(const std::string selectors);
    const NodeList querySelectorAll(const std::string selectors);
};

} // namespace dom
#endif // WASM_DOM_PARENTNODE_H_
