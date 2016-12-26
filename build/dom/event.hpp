#ifndef WASM_DOM_EVENT_H_
#define WASM_DOM_EVENT_H_

#include "eventtarget.hpp"
#include "../_basic.hpp"

namespace dom {

class Event {
  public:
    // constants
    static const unsigned short NONE = 0;
    static const unsigned short CAPTURING_PHASE = 1;
    static const unsigned short AT_TARGET = 2;
    static const unsigned short BUBBLING_PHASE = 3;

    // attributes
    std::string get_type() const;
    nullable<EventTarget> get_target() const;
    nullable<EventTarget> get_currentTarget() const;
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

} // namespace dom
#endif // WASM_DOM_EVENT_H_