#pragma once
#include "node.hpp"
#include "../_basic.hpp"

namespace dom {

class NodeFilter {
  public:
    // constants
    static const unsigned short FILTER_ACCEPT = 1;
    static const unsigned short FILTER_REJECT = 2;
    static const unsigned short FILTER_SKIP = 3;
    static const unsigned long SHOW_ALL = 4294967295;
    static const unsigned long SHOW_ELEMENT = 1;
    static const unsigned long SHOW_ATTRIBUTE = 2;
    static const unsigned long SHOW_TEXT = 4;
    static const unsigned long SHOW_CDATA_SECTION = 8;
    static const unsigned long SHOW_ENTITY_REFERENCE = 16;
    static const unsigned long SHOW_ENTITY = 32;
    static const unsigned long SHOW_PROCESSING_INSTRUCTION = 64;
    static const unsigned long SHOW_COMMENT = 128;
    static const unsigned long SHOW_DOCUMENT = 256;
    static const unsigned long SHOW_DOCUMENT_TYPE = 512;
    static const unsigned long SHOW_DOCUMENT_FRAGMENT = 1024;
    static const unsigned long SHOW_NOTATION = 2048;

    // methods
    const unsigned short acceptNode(const Node node);
};

} // namespace dom
