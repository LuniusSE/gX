/*
// Events
*/

#ifndef _GX_EVENT_
#define _GX_EVENT_

#include "core/Namespace.hpp"
#include "core/Types.hpp"

_GX_BEGIN

/**
 * Event Classifications
 **/
enum Events {
    Key,
    Char,
    Mouse,
    Motion,
    Scroll,

    Window,
};

/**
 * Types of Events
 **/
enum class EventTypes {
    KeyPressed,
    KeyReleased,
    KeyRepeat,

    MouseButtonPressed,
    MouseButtonReleased,

    MouseMotion,
    MouseScrolled,

    WindowResized,
    WindowMoved,
    WindowClosed
};

class Event {
friend class EventMessanger;
private:
    bool m_EventHandled;

public:
    inline Event() : m_EventHandled(false) {}
    virtual ~Event() = default;

    virtual EventTypes GetEventType() const = 0;
    virtual uInt GetEventClass() const = 0;

    inline bool IsEventClass(const uInt& _eClass) const
    { return (GetEventClass() & _eClass); }

    inline bool IsHandled() const
    { return m_EventHandled; }

};

_GX_END

#endif