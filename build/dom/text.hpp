#ifndef WASM_DOM_TEXT_H_
#define WASM_DOM_TEXT_H_

#include "characterdata.hpp"
#include "../_basic.hpp"

namespace dom {

class Text : CharacterData {
  public:
    // attributes
    std::string get_wholeText() const;

    // methods
    const Text splitText(const unsigned long offset);
};

} // namespace dom
#endif // WASM_DOM_TEXT_H_