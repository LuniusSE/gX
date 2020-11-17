/*
// Mouse Events
*/

#ifndef _GX_MOUSE_EVENTS_
#define _GX_MOUSE_EVENTS_

#include "core/Namespace.hpp"
#include "core/Types.hpp"
#include "io/Events.hpp"

_GX_BEGIN

class MouseButtonEvent : public Event {
protected:
    uInt m_Button;
    
    uInt m_X;
    uInt m_Y;

public:
    inline MouseButtonEvent(const uInt& _Button, const uInt& _X, const uInt& _Y)
        : m_Button(_Button), m_X(_X), m_Y(_Y) {}

    inline uInt GetButton() const 
    { return m_Button; }

    inline uInt GetX() const 
    { return m_X; }

    inline uInt GetY() const 
    { return m_Y; }

    inline virtual uInt GetEventClass() const override
    { return Events::Mouse; }

};

class MouseButtonPressedEvent : public MouseButtonEvent {
public:
    inline MouseButtonPressedEvent(const uInt& _Button, const uInt& _X, const uInt& _Y)
    : MouseButtonEvent(_Button, _X, _Y) {}

    inline static EventTypes GetStaticType()
    { return EventTypes::MouseButtonPressed; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

class MouseButtonReleasedEvent : public MouseButtonEvent {
public:
    inline MouseButtonReleasedEvent(const uInt& _Button, const uInt& _X, const uInt& _Y)
    : MouseButtonEvent(_Button, _X, _Y) {}

    inline static EventTypes GetStaticType()
    { return EventTypes::MouseButtonReleased; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

class MouseMotionEvent : public Event {
protected:    
    uInt m_X;
    uInt m_Y;

public:
    inline MouseMotionEvent(const uInt& _X, const uInt& _Y)
        : m_X(_X), m_Y(_Y) {}

    inline uInt GetX() const 
    { return m_X; }

    inline uInt GetY() const 
    { return m_Y; }

    inline virtual uInt GetEventClass() const override
    { return Events::Motion | Events::Mouse; }

    inline static EventTypes GetStaticType()
    { return EventTypes::MouseMotion; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

class MouseScrollEvent : public Event {
protected:    
    float m_Scroll;

public:
    inline MouseScrollEvent(const float& _Scroll)
        : m_Scroll(_Scroll) {}

    inline float GetScroll() const 
    { return m_Scroll; }

    inline virtual uInt GetEventClass() const override
    { return  Events::Mouse | Events::Scroll; }

    inline static EventTypes GetStaticType()
    { return EventTypes::MouseScrolled; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

_GX_END

#endif