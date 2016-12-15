#pragma once
#include "documentfragment.hpp"
#include "shadowrootmode.hpp"
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class ShadowRoot : DocumentFragment {
  // attributes
  ShadowRootMode get_mode() const;
  Element get_host() const;
};

} // namespace dom
