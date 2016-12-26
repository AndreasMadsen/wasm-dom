#ifndef WASM_DOM_DOCUMENTTYPE_H_
#define WASM_DOM_DOCUMENTTYPE_H_

#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class DocumentType : public Node {
  public:
    // attributes
    std::string get_name() const;
    std::string get_publicId() const;
    std::string get_systemId() const;
};

} // namespace dom
#endif // WASM_DOM_DOCUMENTTYPE_H_
