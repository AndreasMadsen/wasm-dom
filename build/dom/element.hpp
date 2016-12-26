#ifndef WASM_DOM_ELEMENT_H_
#define WASM_DOM_ELEMENT_H_

#include "node.hpp"
#include "domtokenlist.hpp"
#include "namednodemap.hpp"
#include "attr.hpp"
#include "shadowroot.hpp"
#include "shadowrootinit.hpp"
#include "htmlcollection.hpp"
#include "../_basic.hpp"

namespace dom {

class Element : public Node {
  public:
    // attributes
    nullable<std::string> get_namespaceURI() const;
    nullable<std::string> get_prefix() const;
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
    nullable<ShadowRoot> get_shadowRoot() const;

    // methods
    const bool hasAttributes();
    const std::vector<std::string> getAttributeNames();
    const nullable<std::string> getAttribute(const std::string qualifiedName);
    const nullable<std::string> getAttributeNS(const nullable<std::string> ns, const std::string localName);
    const void setAttribute(const std::string qualifiedName, const std::string value);
    const void setAttributeNS(const nullable<std::string> ns, const std::string qualifiedName, const std::string value);
    const void removeAttribute(const std::string qualifiedName);
    const void removeAttributeNS(const nullable<std::string> ns, const std::string localName);
    const bool hasAttribute(const std::string qualifiedName);
    const bool hasAttributeNS(const nullable<std::string> ns, const std::string localName);
    const nullable<Attr> getAttributeNode(const std::string qualifiedName);
    const nullable<Attr> getAttributeNodeNS(const nullable<std::string> ns, const std::string localName);
    const nullable<Attr> setAttributeNode(const Attr attr);
    const nullable<Attr> setAttributeNodeNS(const Attr attr);
    const Attr removeAttributeNode(const Attr attr);
    const ShadowRoot attachShadow(const ShadowRootInit init);
    const nullable<Element> closest(const std::string selectors);
    const bool matches(const std::string selectors);
    const bool webkitMatchesSelector(const std::string selectors);
    const HTMLCollection getElementsByTagName(const std::string qualifiedName);
    const HTMLCollection getElementsByTagNameNS(const nullable<std::string> ns, const std::string localName);
    const HTMLCollection getElementsByClassName(const std::string classNames);
    const nullable<Element> insertAdjacentElement(const std::string where, const Element element);
    const void insertAdjacentText(const std::string where, const std::string data);
};

} // namespace dom
#endif // WASM_DOM_ELEMENT_H_
