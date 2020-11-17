/*
// Events
*/

#ifndef _GX_IO_KEY_EVENTS_
#define _GX_IO_KEY_EVENTS_

/** Includes **/
#include <common/Namespace.hpp>
#include <common/Types.hpp>

#include <io/Events.hpp>

_GX_BEGIN

/**
 * 
 **/
class KeyEvent : public Event
{
protected:
    uInt m_Key;

public:
    inline KeyEvent(const uInt& _Key) : m_Key(_Key) {}

    inline uInt GetKey() const 
    { return m_Key; }

    inline virtual uInt GetEventClass() const override
    { return Events::Key; }

};

/**
 * 
 **/
class CharEvent : public Event
{
private:
    char m_Character;
    
public:
    inline CharEvent(const char& _Character)
        : m_Character(_Character) {}

    inline char GetChar() const 
    { return m_Character; }

    inline virtual uInt GetEventClass() const override
    { return Events::Key | Events::Char; }

    inline static EventTypes GetStaticType()
    { return EventTypes::KeyPressed; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

/**
 * 
 **/
class KeyPressedEvent : public KeyEvent
{
private:
    uInt m_RepeatCount;

public:
    inline KeyPressedEvent(const uInt& _Key, const uInt& _RepeatCount)
        : KeyEvent(_Key), m_RepeatCount(_RepeatCount) {}

    inline uInt GetRepeatCount() const
    { return m_RepeatCount; }

    inline static EventTypes GetStaticType()
    { return EventTypes::KeyPressed; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

/**
 * 
 **/
class KeyReleasedEvent : public KeyEvent
{
public:
    inline KeyReleasedEvent(const uInt& _Key)
        : KeyEvent(_Key) {}

    inline static EventTypes GetStaticType()
    { return EventTypes::KeyReleased; }

    inline virtual EventTypes GetEventType() const override
    { return GetStaticType(); }

};

_GX_END

#endif