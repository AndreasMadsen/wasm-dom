#pragma once
#include "eventtarget.hpp"
#include "document.hpp"
#include "getrootnodeoptions.hpp"
#include "element.hpp"
#include "nodelist.hpp"
#include "../_basic.hpp"

namespace dom {

class Node : EventTarget {
  public:
    // constants
    static const unsigned short ELEMENT_NODE = 1;
    static const unsigned short ATTRIBUTE_NODE = 2;
    static const unsigned short TEXT_NODE = 3;
    static const unsigned short CDATA_SECTION_NODE = 4;
    static const unsigned short ENTITY_REFERENCE_NODE = 5;
    static const unsigned short ENTITY_NODE = 6;
    static const unsigned short PROCESSING_INSTRUCTION_NODE = 7;
    static const unsigned short COMMENT_NODE = 8;
    static const unsigned short DOCUMENT_NODE = 9;
    static const unsigned short DOCUMENT_TYPE_NODE = 10;
    static const unsigned short DOCUMENT_FRAGMENT_NODE = 11;
    static const unsigned short NOTATION_NODE = 12;
    static const unsigned short DOCUMENT_POSITION_DISCONNECTED = 1;
    static const unsigned short DOCUMENT_POSITION_PRECEDING = 2;
    static const unsigned short DOCUMENT_POSITION_FOLLOWING = 4;
    static const unsigned short DOCUMENT_POSITION_CONTAINS = 8;
    static const unsigned short DOCUMENT_POSITION_CONTAINED_BY = 16;
    static const unsigned short DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 32;

    // attributes
    unsigned short get_nodeType() const;
    std::string get_nodeName() const;
    std::string get_baseURI() const;
    bool get_isConnected() const;
    optional<Document> get_ownerDocument() const;
    optional<Node> get_parentNode() const;
    optional<Element> get_parentElement() const;
    NodeList get_childNodes() const;
    optional<Node> get_firstChild() const;
    optional<Node> get_lastChild() const;
    optional<Node> get_previousSibling() const;
    optional<Node> get_nextSibling() const;
    optional<std::string> get_nodeValue() const;
    optional<std::string> set_nodeValue(const optional<std::string> nodeValue);
    optional<std::string> get_textContent() const;
    optional<std::string> set_textContent(const optional<std::string> textContent);

    // methods
    const Node getRootNode(const GetRootNodeOptions options);
    const bool hasChildNodes();
    const void normalize();
    const Node cloneNode(const bool deep = false);
    const bool isEqualNode(const optional<Node> otherNode);
    const bool isSameNode(const optional<Node> otherNode);
    const unsigned short compareDocumentPosition(const Node other);
    const bool contains(const optional<Node> other);
    const optional<std::string> lookupPrefix(const optional<std::string> ns);
    const optional<std::string> lookupNamespaceURI(const optional<std::string> prefix);
    const bool isDefaultNamespace(const optional<std::string> ns);
    const Node insertBefore(const Node node, const optional<Node> child);
    const Node appendChild(const Node node);
    const Node replaceChild(const Node node, const Node child);
    const Node removeChild(const Node child);
};

} // namespace dom
