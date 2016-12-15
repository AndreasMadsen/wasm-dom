#pragma once
#include <string>
#include <vector>

namespace dom {

// === TEMP ===
template<typename T>
class optional;

typedef void* any;
// === TEMP ===

class Event {
  // constants
  static const unsigned short NONE = 0;
  static const unsigned short CAPTURING_PHASE = 1;
  static const unsigned short AT_TARGET = 2;
  static const unsigned short BUBBLING_PHASE = 3;

  // attributes
  std::string get_type() const;
  optional<EventTarget> get_target() const;
  optional<EventTarget> get_currentTarget() const;
  unsigned short get_eventPhase() const;
  bool get_bubbles() const;
  bool get_cancelable() const;
  bool get_defaultPrevented() const;
  bool get_composed() const;
  bool get_isTrusted() const;
  long int get_timeStamp() const;

  // methods
  const std::vector<EventTarget> composedPath();
  const void stopPropagation();
  const void stopImmediatePropagation();
  const void preventDefault();
  const void initEvent(const std::string type, const bool bubbles, const bool cancelable);
};

struct EventInit {
  bool bubbles = false;
  bool cancelable = false;
  bool composed = false;
};

class CustomEvent : Event {
  // attributes
  any get_detail() const;

  // methods
  const void initCustomEvent(const std::string type, const bool bubbles, const bool cancelable, const any detail);
};

struct CustomEventInit : EventInit {
  any detail = NULL;
};

class EventTarget {
  // methods
  const void addEventListener(const std::string type, const optional<EventListener> callback, const union<AddEventListenerOptions, bool> options);
  const void removeEventListener(const std::string type, const optional<EventListener> callback, const union<EventListenerOptions, bool> options);
  const bool dispatchEvent(const Event event);
};

struct EventListenerOptions {
  bool capture = false;
};

struct AddEventListenerOptions : EventListenerOptions {
  bool passive = false;
  bool once = false;
};

class NonElementParentNode {
  // methods
  const optional<Element> getElementById(const std::string elementId);
};

class DocumentOrShadowRoot {
};

class ParentNode {
  // attributes
  HTMLCollection get_children() const;
  optional<Element> get_firstElementChild() const;
  optional<Element> get_lastElementChild() const;
  unsigned long get_childElementCount() const;

  // methods
  const void prepend(const union<Node, std::string> nodes);
  const void append(const union<Node, std::string> nodes);
  const optional<Element> querySelector(const std::string selectors);
  const NodeList querySelectorAll(const std::string selectors);
};

class NonDocumentTypeChildNode {
  // attributes
  optional<Element> get_previousElementSibling() const;
  optional<Element> get_nextElementSibling() const;
};

class ChildNode {
  // methods
  const void before(const union<Node, std::string> nodes);
  const void after(const union<Node, std::string> nodes);
  const void replaceWith(const union<Node, std::string> nodes);
  const void remove();
};

class Slotable {
  // attributes
  optional<HTMLSlotElement> get_assignedSlot() const;
};

class NodeList {
  // attributes
  unsigned long get_length() const;

  // methods
  const optional<Node> item(const unsigned long index);
};

class HTMLCollection {
  // attributes
  unsigned long get_length() const;

  // methods
  const optional<Element> item(const unsigned long index);
  const optional<Element> namedItem(const std::string name);
};

class MutationObserver {
  // methods
  const void observe(const Node target, const MutationObserverInit options);
  const void disconnect();
  const std::vector<MutationRecord> takeRecords();
};

struct MutationObserverInit {
  bool childList = false;
  bool attributes;
  bool characterData;
  bool subtree = false;
  bool attributeOldValue;
  bool characterDataOldValue;
  std::vector<std::string> attributeFilter;
};

class MutationRecord {
  // attributes
  std::string get_type() const;
  Node get_target() const;
  NodeList get_addedNodes() const;
  NodeList get_removedNodes() const;
  optional<Node> get_previousSibling() const;
  optional<Node> get_nextSibling() const;
  optional<std::string> get_attributeName() const;
  optional<std::string> get_attributeNamespace() const;
  optional<std::string> get_oldValue() const;
};

class Node : EventTarget {
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
  const optional<std::string> lookupPrefix(const optional<std::string> namespace);
  const optional<std::string> lookupNamespaceURI(const optional<std::string> prefix);
  const bool isDefaultNamespace(const optional<std::string> namespace);
  const Node insertBefore(const Node node, const optional<Node> child);
  const Node appendChild(const Node node);
  const Node replaceChild(const Node node, const Node child);
  const Node removeChild(const Node child);
};

struct GetRootNodeOptions {
  bool composed = false;
};

class Document : Node {
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
  const HTMLCollection getElementsByTagNameNS(const optional<std::string> namespace, const std::string localName);
  const HTMLCollection getElementsByClassName(const std::string classNames);
  const Element createElement(const std::string localName, const ElementCreationOptions options);
  const Element createElementNS(const optional<std::string> namespace, const std::string qualifiedName, const ElementCreationOptions options);
  const DocumentFragment createDocumentFragment();
  const Text createTextNode(const std::string data);
  const CDATASection createCDATASection(const std::string data);
  const Comment createComment(const std::string data);
  const ProcessingInstruction createProcessingInstruction(const std::string target, const std::string data);
  const Node importNode(const Node node, const bool deep = false);
  const Node adoptNode(const Node node);
  const Attr createAttribute(const std::string localName);
  const Attr createAttributeNS(const optional<std::string> namespace, const std::string qualifiedName);
  const Event createEvent(const std::string interface);
  const Range createRange();
  const NodeIterator createNodeIterator(const Node root, const unsigned long whatToShow = 4294967295, const optional<NodeFilter> filter = NULL);
  const TreeWalker createTreeWalker(const Node root, const unsigned long whatToShow = 4294967295, const optional<NodeFilter> filter = NULL);
};

class XMLDocument : Document {
};

struct ElementCreationOptions {
  std::string is;
};

class DOMImplementation {
  // methods
  const DocumentType createDocumentType(const std::string qualifiedName, const std::string publicId, const std::string systemId);
  const XMLDocument createDocument(const optional<std::string> namespace, const std::string qualifiedName, const optional<DocumentType> doctype = NULL);
  const Document createHTMLDocument(const std::string title);
  const bool hasFeature();
};

class DocumentType : Node {
  // attributes
  std::string get_name() const;
  std::string get_publicId() const;
  std::string get_systemId() const;
};

class DocumentFragment : Node {
};

class ShadowRoot : DocumentFragment {
  // attributes
  ShadowRootMode get_mode() const;
  Element get_host() const;
};

enum ShadowRootMode { open, closed };

class Element : Node {
  // attributes
  optional<std::string> get_namespaceURI() const;
  optional<std::string> get_prefix() const;
  std::string get_localName() const;
  std::string get_tagName() const;
  std::string get_id() const;
  std::string set_id(const std::string id);
  std::string get_className() const;
  std::string set_className(const std::string className);
  DOMTokenList get_classList() const;
  std::string get_slot() const;
  std::string set_slot(const std::string slot);
  NamedNodeMap get_attributes() const;
  optional<ShadowRoot> get_shadowRoot() const;

  // methods
  const bool hasAttributes();
  const std::vector<std::string> getAttributeNames();
  const optional<std::string> getAttribute(const std::string qualifiedName);
  const optional<std::string> getAttributeNS(const optional<std::string> namespace, const std::string localName);
  const void setAttribute(const std::string qualifiedName, const std::string value);
  const void setAttributeNS(const optional<std::string> namespace, const std::string qualifiedName, const std::string value);
  const void removeAttribute(const std::string qualifiedName);
  const void removeAttributeNS(const optional<std::string> namespace, const std::string localName);
  const bool hasAttribute(const std::string qualifiedName);
  const bool hasAttributeNS(const optional<std::string> namespace, const std::string localName);
  const optional<Attr> getAttributeNode(const std::string qualifiedName);
  const optional<Attr> getAttributeNodeNS(const optional<std::string> namespace, const std::string localName);
  const optional<Attr> setAttributeNode(const Attr attr);
  const optional<Attr> setAttributeNodeNS(const Attr attr);
  const Attr removeAttributeNode(const Attr attr);
  const ShadowRoot attachShadow(const ShadowRootInit init);
  const optional<Element> closest(const std::string selectors);
  const bool matches(const std::string selectors);
  const bool webkitMatchesSelector(const std::string selectors);
  const HTMLCollection getElementsByTagName(const std::string qualifiedName);
  const HTMLCollection getElementsByTagNameNS(const optional<std::string> namespace, const std::string localName);
  const HTMLCollection getElementsByClassName(const std::string classNames);
  const optional<Element> insertAdjacentElement(const std::string where, const Element element);
  const void insertAdjacentText(const std::string where, const std::string data);
};

struct ShadowRootInit {
  ShadowRootMode mode;
};

class NamedNodeMap {
  // attributes
  unsigned long get_length() const;

  // methods
  const optional<Attr> item(const unsigned long index);
  const optional<Attr> getNamedItem(const std::string qualifiedName);
  const optional<Attr> getNamedItemNS(const optional<std::string> namespace, const std::string localName);
  const optional<Attr> setNamedItem(const Attr attr);
  const optional<Attr> setNamedItemNS(const Attr attr);
  const Attr removeNamedItem(const std::string qualifiedName);
  const Attr removeNamedItemNS(const optional<std::string> namespace, const std::string localName);
};

class Attr : Node {
  // attributes
  optional<std::string> get_namespaceURI() const;
  optional<std::string> get_prefix() const;
  std::string get_localName() const;
  std::string get_name() const;
  std::string get_value() const;
  std::string set_value(const std::string value);
  optional<Element> get_ownerElement() const;
  bool get_specified() const;
};

class CharacterData : Node {
  // attributes
  std::string get_data() const;
  std::string set_data(const std::string data);
  unsigned long get_length() const;

  // methods
  const std::string substringData(const unsigned long offset, const unsigned long count);
  const void appendData(const std::string data);
  const void insertData(const unsigned long offset, const std::string data);
  const void deleteData(const unsigned long offset, const unsigned long count);
  const void replaceData(const unsigned long offset, const unsigned long count, const std::string data);
};

class Text : CharacterData {
  // attributes
  std::string get_wholeText() const;

  // methods
  const Text splitText(const unsigned long offset);
};

class CDATASection : Text {
};

class ProcessingInstruction : CharacterData {
  // attributes
  std::string get_target() const;
};

class Comment : CharacterData {
};

class Range {
  // constants
  static const unsigned short START_TO_START = 0;
  static const unsigned short START_TO_END = 1;
  static const unsigned short END_TO_END = 2;
  static const unsigned short END_TO_START = 3;

  // attributes
  Node get_startContainer() const;
  unsigned long get_startOffset() const;
  Node get_endContainer() const;
  unsigned long get_endOffset() const;
  bool get_collapsed() const;
  Node get_commonAncestorContainer() const;

  // methods
  const void setStart(const Node node, const unsigned long offset);
  const void setEnd(const Node node, const unsigned long offset);
  const void setStartBefore(const Node node);
  const void setStartAfter(const Node node);
  const void setEndBefore(const Node node);
  const void setEndAfter(const Node node);
  const void collapse(const bool toStart = false);
  const void selectNode(const Node node);
  const void selectNodeContents(const Node node);
  const short compareBoundaryPoints(const unsigned short how, const Range sourceRange);
  const void deleteContents();
  const DocumentFragment extractContents();
  const DocumentFragment cloneContents();
  const void insertNode(const Node node);
  const void surroundContents(const Node newParent);
  const Range cloneRange();
  const void detach();
  const bool isPointInRange(const Node node, const unsigned long offset);
  const short comparePoint(const Node node, const unsigned long offset);
  const bool intersectsNode(const Node node);
};

class NodeIterator {
  // attributes
  Node get_root() const;
  Node get_referenceNode() const;
  bool get_pointerBeforeReferenceNode() const;
  unsigned long get_whatToShow() const;
  optional<NodeFilter> get_filter() const;

  // methods
  const optional<Node> nextNode();
  const optional<Node> previousNode();
  const void detach();
};

class TreeWalker {
  // attributes
  Node get_root() const;
  unsigned long get_whatToShow() const;
  optional<NodeFilter> get_filter() const;
  Node get_currentNode() const;
  Node set_currentNode(const Node currentNode);

  // methods
  const optional<Node> parentNode();
  const optional<Node> firstChild();
  const optional<Node> lastChild();
  const optional<Node> previousSibling();
  const optional<Node> nextSibling();
  const optional<Node> previousNode();
  const optional<Node> nextNode();
};

class DOMTokenList {
  // attributes
  unsigned long get_length() const;
  std::string get_value() const;
  std::string set_value(const std::string value);

  // methods
  const optional<std::string> item(const unsigned long index);
  const bool contains(const std::string token);
  const void add(const std::string tokens);
  const void remove(const std::string tokens);
  const bool toggle(const std::string token, const bool force);
  const void replace(const std::string token, const std::string newToken);
  const bool supports(const std::string token);
};

} // namespace dom
