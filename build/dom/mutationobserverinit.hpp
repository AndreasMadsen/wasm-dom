#ifndef WASM_DOM_MUTATIONOBSERVERINIT_H_
#define WASM_DOM_MUTATIONOBSERVERINIT_H_

#include "../_basic.hpp"

namespace dom {

struct MutationObserverInit {
  bool childList = false;
  bool attributes;
  bool characterData;
  bool subtree = false;
  bool attributeOldValue;
  bool characterDataOldValue;
  std::vector<std::string> attributeFilter;
};

} // namespace dom
#endif // WASM_DOM_MUTATIONOBSERVERINIT_H_
