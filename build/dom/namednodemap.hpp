#ifndef WASM_DOM_NAMEDNODEMAP_H_
#define WASM_DOM_NAMEDNODEMAP_H_

#include "attr.hpp"
#include "../_basic.hpp"

namespace dom {

class NamedNodeMap {
  public:
    // attributes
    unsigned long get_length() const;

    // methods
    const nullable<Attr> item(const unsigned long index);
    const nullable<Attr> getNamedItem(const std::string qualifiedName);
    const nullable<Attr> getNamedItemNS(const nullable<std::string> ns, const std::string localName);
    const nullable<Attr> setNamedItem(const Attr attr);
    const nullable<Attr> setNamedItemNS(const Attr attr);
    const Attr removeNamedItem(const std::string qualifiedName);
    const Attr removeNamedItemNS(const nullable<std::string> ns, const std::string localName);
};

} // namespace dom
#endif // WASM_DOM_NAMEDNODEMAP_H_