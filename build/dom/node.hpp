#ifndef WASM_DOM_NODE_H_
#define WASM_DOM_NODE_H_

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
    nullable<Document> get_ownerDocument() const;
    nullable<Node> get_parentNode() const;
    nullable<Element> get_parentElement() const;
    NodeList get_childNodes() const;
    nullable<Node> get_firstChild() const;
    nullable<Node> get_lastChild() const;
    nullable<Node> get_previousSibling() const;
    nullable<Node> get_nextSibling() const;
    nullable<std::string> get_nodeValue() const;
    nullable<std::string> set_nodeValue(const nullable<std::string> nodeValue);
    nullable<std::string> get_textContent() const;
    nullable<std::string> set_textContent(const nullable<std::string> textContent);

    // methods
    const Node getRootNode(const optional<GetRootNodeOptions> options);
    const bool hasChildNodes();
    const void normalize();
    const Node cloneNode(const optional<bool> deep = false);
    const bool isEqualNode(const nullable<Node> otherNode);
    const bool isSameNode(const nullable<Node> otherNode);
    const unsigned short compareDocumentPosition(const Node other);
    const bool contains(const nullable<Node> other);
    const nullable<std::string> lookupPrefix(const nullable<std::string> ns);
    const nullable<std::string> lookupNamespaceURI(const nullable<std::string> prefix);
    const bool isDefaultNamespace(const nullable<std::string> ns);
    const Node insertBefore(const Node node, const nullable<Node> child);
    const Node appendChild(const Node node);
    const Node replaceChild(const Node node, const Node child);
    const Node removeChild(const Node child);
};

} // namespace dom
#endif // WASM_DOM_NODE_H_