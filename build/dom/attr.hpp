#ifndef WASM_DOM_ATTR_H_
#define WASM_DOM_ATTR_H_

#include "node.hpp"
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class Attr : Node {
  public:
    // attributes
    nullable<std::string> get_namespaceURI() const;
    nullable<std::string> get_prefix() const;
    std::string get_localName() const;
    std::string get_name() const;
    std::string get_value() const;
    std::string set_value(const std::string value);
    nullable<Element> get_ownerElement() const;
    bool get_specified() const;
};

} // namespace dom
#endif // WASM_DOM_ATTR_H_