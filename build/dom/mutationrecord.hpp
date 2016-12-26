#ifndef WASM_DOM_MUTATIONRECORD_H_
#define WASM_DOM_MUTATIONRECORD_H_

#include "node.hpp"
#include "nodelist.hpp"
#include "../_basic.hpp"

namespace dom {

class MutationRecord {
  public:
    // attributes
    std::string get_type() const;
    Node get_target() const;
    NodeList get_addedNodes() const;
    NodeList get_removedNodes() const;
    nullable<Node> get_previousSibling() const;
    nullable<Node> get_nextSibling() const;
    nullable<std::string> get_attributeName() const;
    nullable<std::string> get_attributeNamespace() const;
    nullable<std::string> get_oldValue() const;
};

} // namespace dom
#endif // WASM_DOM_MUTATIONRECORD_H_
