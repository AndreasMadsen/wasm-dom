#pragma once
#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class DocumentType : Node {
  // attributes
  std::string get_name() const;
  std::string get_publicId() const;
  std::string get_systemId() const;
};

} // namespace dom
