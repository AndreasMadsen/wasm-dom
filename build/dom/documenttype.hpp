#pragma once
#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class DocumentType : Node {
  public:
    // attributes
    std::string get_name() const;
    std::string get_publicId() const;
    std::string get_systemId() const;
};

} // namespace dom
