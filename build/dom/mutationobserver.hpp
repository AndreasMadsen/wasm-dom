#pragma once
#include "node.hpp"
#include "mutationobserverinit.hpp"
#include "mutationrecord.hpp"
#include "../_basic.hpp"

namespace dom {

class MutationObserver {
  public:
    // methods
    const void observe(const Node target, const MutationObserverInit options);
    const void disconnect();
    const std::vector<MutationRecord> takeRecords();
};

} // namespace dom
