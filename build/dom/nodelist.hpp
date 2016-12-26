#ifndef WASM_DOM_NODELIST_H_
#define WASM_DOM_NODELIST_H_

#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class NodeList {
  public:
    // attributes
    unsigned long get_length() const;

    // methods
    const nullable<Node> item(const unsigned long index);
};

} // namespace dom
#endif // WASM_DOM_NODELIST_H_
