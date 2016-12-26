#ifndef WASM_DOM_NONDOCUMENTTYPECHILDNODE_H_
#define WASM_DOM_NONDOCUMENTTYPECHILDNODE_H_

#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class NonDocumentTypeChildNode {
  public:
    // attributes
    nullable<Element> get_previousElementSibling() const;
    nullable<Element> get_nextElementSibling() const;
};

} // namespace dom
#endif // WASM_DOM_NONDOCUMENTTYPECHILDNODE_H_