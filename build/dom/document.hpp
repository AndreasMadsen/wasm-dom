#pragma once
#include "node.hpp"
#include "domimplementation.hpp"
#include "documenttype.hpp"
#include "element.hpp"
#include "htmlcollection.hpp"
#include "elementcreationoptions.hpp"
#include "documentfragment.hpp"
#include "text.hpp"
#include "cdatasection.hpp"
#include "comment.hpp"
#include "processinginstruction.hpp"
#include "attr.hpp"
#include "event.hpp"
#include "range.hpp"
#include "nodeiterator.hpp"
#include "nodefilter.hpp"
#include "treewalker.hpp"
#include "../_basic.hpp"

namespace dom {

class Document : Node {
  public:
    // attributes
    DOMImplementation get_implementation() const;
    std::string get_URL() const;
    std::string get_documentURI() const;
    std::string get_origin() const;
    std::string get_compatMode() const;
    std::string get_characterSet() const;
    std::string get_charset() const;
    std::string get_inputEncoding() const;
    std::string get_contentType() const;
    optional<DocumentType> get_doctype() const;
    optional<Element> get_documentElement() const;

    // methods
    const HTMLCollection getElementsByTagName(const std::string qualifiedName);
    const HTMLCollection getElementsByTagNameNS(const optional<std::string> ns, const std::string localName);
    const HTMLCollection getElementsByClassName(const std::string classNames);
    const Element createElement(const std::string localName, const ElementCreationOptions options);
    const Element createElementNS(const optional<std::string> ns, const std::string qualifiedName, const ElementCreationOptions options);
    const DocumentFragment createDocumentFragment();
    const Text createTextNode(const std::string data);
    const CDATASection createCDATASection(const std::string data);
    const Comment createComment(const std::string data);
    const ProcessingInstruction createProcessingInstruction(const std::string target, const std::string data);
    const Node importNode(const Node node, const bool deep = false);
    const Node adoptNode(const Node node);
    const Attr createAttribute(const std::string localName);
    const Attr createAttributeNS(const optional<std::string> ns, const std::string qualifiedName);
    const Event createEvent(const std::string interface);
    const Range createRange();
    const NodeIterator createNodeIterator(const Node root, const unsigned long whatToShow = 4294967295, const optional<NodeFilter> filter = NULL);
    const TreeWalker createTreeWalker(const Node root, const unsigned long whatToShow = 4294967295, const optional<NodeFilter> filter = NULL);
};

} // namespace dom
