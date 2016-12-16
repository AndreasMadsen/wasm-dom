#pragma once
#include "characterdata.hpp"
#include "../_basic.hpp"

namespace dom {

class ProcessingInstruction : CharacterData {
  public:
    // attributes
    std::string get_target() const;
};

} // namespace dom
