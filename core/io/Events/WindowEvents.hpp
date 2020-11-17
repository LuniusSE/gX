/*
// Window Events
*/

#ifndef _GX_WINDOW_EVENTS_
#define _GX_WINDOW_EVENTS_

#include "core/Namespace.hpp"
#include "core/Types.hpp"
#include "io/Events.hpp"

_GX_BEGIN

class WindowResizedEvent : public Event {
protected:
    uInt m_Width, m_Height;

public:
    inline WindowResizedEvent(const uInt& _Width, const uInt& _Height)
        : m_Width(_Width), m_Height(_Height) {}

    inline uInt GetWidth() const 
    { return m_Width; }

    inline uInt GetHeight() const 
    { return m_Height; }

    inline virtual uInt GetEventClass() const override
    { return Events::Window; }

    inline static EventTypes GetStaticType()
    { return EventTypes::WindowResized; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

class WindowMovedEvent : public Event {
protected:
    uInt m_X, m_Y;

public:
    inline WindowMovedEvent(const uInt& _X, const uInt& _Y)
        : m_X(_X), m_Y(_Y) {}

    inline uInt GetX() const 
    { return m_X; }

    inline uInt GetY() const 
    { return m_Y; }

    inline virtual uInt GetEventClass() const override
    { return Events::Window; }

    inline static EventTypes GetStaticType()
    { return EventTypes::WindowMoved; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

class WindowClosedEvent : public Event {
public:
    inline WindowClosedEvent() {}

    inline virtual uInt GetEventClass() const override
    { return Events::Window; }

    inline static EventTypes GetStaticType()
    { return EventTypes::WindowClosed; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

_GX_END

#endif