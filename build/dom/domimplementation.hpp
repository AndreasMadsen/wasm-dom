#pragma once
#include "documenttype.hpp"
#include "xmldocument.hpp"
#include "document.hpp"
#include "../_basic.hpp"

namespace dom {

class DOMImplementation {
  public:
    // methods
    const DocumentType createDocumentType(const std::string qualifiedName, const std::string publicId, const std::string systemId);
    const XMLDocument createDocument(const optional<std::string> ns, const std::string qualifiedName, const optional<DocumentType> doctype = NULL);
    const Document createHTMLDocument(const std::string title);
    const bool hasFeature();
};

} // namespace dom
