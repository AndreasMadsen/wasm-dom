#ifndef WASM_DOM_MUTATIONOBSERVER_H_
#define WASM_DOM_MUTATIONOBSERVER_H_

#include "node.hpp"
#include "mutationobserverinit.hpp"
#include "mutationrecord.hpp"
#include "../_basic.hpp"

namespace dom {

class MutationObserver {
  public:
    // methods
    const void observe(const Node target, const optional<MutationObserverInit> options);
    const void disconnect();
    const std::vector<MutationRecord> takeRecords();
};

} // namespace dom
#endif // WASM_DOM_MUTATIONOBSERVER_H_