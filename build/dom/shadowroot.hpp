#ifndef WASM_DOM_SHADOWROOT_H_
#define WASM_DOM_SHADOWROOT_H_

#include "documentfragment.hpp"
#include "shadowrootmode.hpp"
#include "element.hpp"
#include "../_basic.hpp"

namespace dom {

class ShadowRoot : DocumentFragment {
  public:
    // attributes
    ShadowRootMode get_mode() const;
    Element get_host() const;
};

} // namespace dom
#endif // WASM_DOM_SHADOWROOT_H_