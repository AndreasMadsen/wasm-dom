#pragma once
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
