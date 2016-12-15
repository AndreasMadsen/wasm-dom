#pragma once
#include "htmlslotelement.hpp"
#include "../_basic.hpp"

namespace dom {

class Slotable {
  // attributes
  optional<HTMLSlotElement> get_assignedSlot() const;
};

} // namespace dom
