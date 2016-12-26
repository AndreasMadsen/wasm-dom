#ifndef WASM_DOM_DOMTOKENLIST_H_
#define WASM_DOM_DOMTOKENLIST_H_

#include "../_basic.hpp"

namespace dom {

class DOMTokenList {
  public:
    // attributes
    unsigned long get_length() const;
    std::string get_value() const;
    std::string set_value(const std::string value);

    // methods
    const nullable<std::string> item(const unsigned long index);
    const bool contains(const std::string token);
    const void add(const std::string tokens);
    const void remove(const std::string tokens);
    const bool toggle(const std::string token);
    const bool toggle(const std::string token, const bool force);
    const void replace(const std::string token, const std::string newToken);
    const bool supports(const std::string token);
};

} // namespace dom
#endif // WASM_DOM_DOMTOKENLIST_H_
