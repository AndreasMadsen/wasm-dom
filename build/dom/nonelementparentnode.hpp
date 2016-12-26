#ifndef WASM_DOM_NONELEMENTPARENTNODE_H_
#define WASM_DOM_NONELEMENTPARENTNODE_H_

#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class NonElementParentNode {
  public:
    // methods
    const nullable<Element> getElementById(const std::string elementId);
};

} // namespace dom
#endif // WASM_DOM_NONELEMENTPARENTNODE_H_
