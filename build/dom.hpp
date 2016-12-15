#pragma once
#include <string>
#include <vector>

struct EventInit {
  bool bubbles = false;
  bool cancelable = false;
  bool composed = false;
};

struct CustomEventInit {
  any detail = NULL;
};

struct EventListenerOptions {
  bool capture = false;
};

struct AddEventListenerOptions {
  bool passive = false;
  bool once = false;
};

struct MutationObserverInit {
  bool childList = false;
  bool attributes;
  bool characterData;
  bool subtree = false;
  bool attributeOldValue;
  bool characterDataOldValue;
  std::vector<std::string> attributeFilter;
};

struct GetRootNodeOptions {
  bool composed = false;
};

struct ElementCreationOptions {
  std::string is;
};

enum ShadowRootMode { open, closed };

struct ShadowRootInit {
  ShadowRootMode mode;
};
