#ifndef WASM_DOM_PROCESSINGINSTRUCTION_H_
#define WASM_DOM_PROCESSINGINSTRUCTION_H_

#include "characterdata.hpp"
#include "../_basic.hpp"

namespace dom {

class ProcessingInstruction : public CharacterData {
  public:
    // attributes
    std::string get_target() const;
};

} // namespace dom
#endif // WASM_DOM_PROCESSINGINSTRUCTION_H_
