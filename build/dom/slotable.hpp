#ifndef WASM_DOM_SLOTABLE_H_
#define WASM_DOM_SLOTABLE_H_

#include "htmlslotelement.hpp"
#include "../_basic.hpp"

namespace dom {

class Slotable {
  public:
    // attributes
    nullable<HTMLSlotElement> get_assignedSlot() const;
};

} // namespace dom
#endif // WASM_DOM_SLOTABLE_H_