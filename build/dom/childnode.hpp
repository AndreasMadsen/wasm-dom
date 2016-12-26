#ifndef WASM_DOM_CHILDNODE_H_
#define WASM_DOM_CHILDNODE_H_

#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class ChildNode {
  public:
    // methods
    const void before(const Node nodes);
    const void before(const std::string nodes);
    const void after(const Node nodes);
    const void after(const std::string nodes);
    const void replaceWith(const Node nodes);
    const void replaceWith(const std::string nodes);
    const void remove();
};

} // namespace dom
#endif // WASM_DOM_CHILDNODE_H_