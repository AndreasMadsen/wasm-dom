#ifndef WASM_DOM_DOMIMPLEMENTATION_H_
#define WASM_DOM_DOMIMPLEMENTATION_H_

#include "documenttype.hpp"
#include "xmldocument.hpp"
#include "document.hpp"
#include "../_basic.hpp"

namespace dom {

class DOMImplementation {
  public:
    // methods
    const DocumentType createDocumentType(const std::string qualifiedName, const std::string publicId, const std::string systemId);
    const XMLDocument createDocument(const nullable<std::string> ns, const std::string qualifiedName, const optional<nullable<DocumentType>> doctype = NULL);
    const Document createHTMLDocument(const optional<std::string> title);
    const bool hasFeature();
};

} // namespace dom
#endif // WASM_DOM_DOMIMPLEMENTATION_H_