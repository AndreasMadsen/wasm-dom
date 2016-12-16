#pragma once
#include "node.hpp"
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class Attr : Node {
  public:
    // attributes
    optional<std::string> get_namespaceURI() const;
    optional<std::string> get_prefix() const;
    std::string get_localName() const;
    std::string get_name() const;
    std::string get_value() const;
    std::string set_value(const std::string value);
    optional<Element> get_ownerElement() const;
    bool get_specified() const;
};

} // namespace dom
