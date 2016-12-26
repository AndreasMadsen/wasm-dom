#ifndef WASM_DOM_CHARACTERDATA_H_
#define WASM_DOM_CHARACTERDATA_H_

#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class CharacterData : public Node {
  public:
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

} // namespace dom
#endif // WASM_DOM_CHARACTERDATA_H_
