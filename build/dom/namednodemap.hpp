#pragma once
#include "attr.hpp"
#include "../_basic.hpp"

namespace dom {

class NamedNodeMap {
  // attributes
  unsigned long get_length() const;

  // methods
  const optional<Attr> item(const unsigned long index);
  const optional<Attr> getNamedItem(const std::string qualifiedName);
  const optional<Attr> getNamedItemNS(const optional<std::string> ns, const std::string localName);
  const optional<Attr> setNamedItem(const Attr attr);
  const optional<Attr> setNamedItemNS(const Attr attr);
  const Attr removeNamedItem(const std::string qualifiedName);
  const Attr removeNamedItemNS(const optional<std::string> ns, const std::string localName);
};

} // namespace dom
