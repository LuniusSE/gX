/*
// Event Messanger
*/

#ifndef _GX_EVENT_MESSANGER_
#define _GX_EVENT_MESSANGER_

#include "core/Namespace.hpp"
#include "core/Types.hpp"
#include "io/Events.hpp"

#include <functional>

_GX_BEGIN

/*! @brief Register object function
 **/
#define GX_EVENT(F) [this](auto&&... _Args) -> decltype(auto) { return this->F(std::forward<decltype(_Args)>(_Args)...); }

/** Event Handler function type **/
using EventHandlerFn = std::function<void(Event&)>;

class EventMessanger {
private:
    Event& m_Event;

public:
    inline EventMessanger(Event& _Event)
    : m_Event(_Event) {}
    
    /*! @brief Register a function to recieve event messages
    **/
    template<typename T, typename F>
    inline bool Register(const F& _Func)
    {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
            m_Event.m_EventHandled |= _Func(static_cast<T&>(m_Event));
            return true;
        }
        return false;
    }

};

_GX_END

#endif