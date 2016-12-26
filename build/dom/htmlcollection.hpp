#ifndef WASM_DOM_HTMLCOLLECTION_H_
#define WASM_DOM_HTMLCOLLECTION_H_

#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class HTMLCollection {
  public:
    // attributes
    unsigned long get_length() const;

    // methods
    const nullable<Element> item(const unsigned long index);
    const nullable<Element> namedItem(const std::string name);
};

} // namespace dom
#endif // WASM_DOM_HTMLCOLLECTION_H_
