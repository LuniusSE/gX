/*
// Mouse InputDevice
*/
#include "MouseDevice.hpp"

_GX_BEGIN

MouseInputDevice::MouseInputDevice()
{
}

MouseInputDevice::~MouseInputDevice()
{
}

bool MouseInputDevice::OnMouseButtonPressedEvent(MouseButtonPressedEvent& _Event)
{
    m_ButtonStates[_Event.GetButton()] = State::Pressed;

    return false;
}

bool MouseInputDevice::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& _Event)
{
    m_ButtonStates[_Event.GetButton()] = State::Released;

    return false;
}

bool MouseInputDevice::OnMouseMotionEvent(MouseMotionEvent& _Event)
{
    m_MouseX = _Event.GetX();
    m_MouseY = _Event.GetY();

    return false;
}

void MouseInputDevice::InitializeDevice(void)
{
    ClearDeviceState();
}

void MouseInputDevice::ShutdownDevice(void)
{
    ClearDeviceState();
}

void MouseInputDevice::ClearDeviceState(void)
{
    for (State& Button : m_ButtonStates)
        Button = State::Released;
}

State MouseInputDevice::GetInputState(const uInt& _uInputHandle) const
{
    return m_ButtonStates[_uInputHandle];
}

float MouseInputDevice::GetInputAxis(const uInt& _uInputHandle) const
{
    switch (_uInputHandle)
    {
    case MouseAxises::Mouse_X:
        return m_MouseX;
    case MouseAxises::Mouse_Y:
        return m_MouseY;
    
    default: break;
    }
 
    return 0.0f;
}

bool MouseInputDevice::GetInputPressed(const uInt& _uInputHandle) const
{
    return (m_ButtonStates[_uInputHandle] == State::Pressed);
}

bool MouseInputDevice::GetInputReleased(const uInt& _uInputHandle) const
{
    return (m_ButtonStates[_uInputHandle] == State::Released);
}

void MouseInputDevice::OnDeviceEvent(Event& _Event)
{
    EventMessanger messanger(_Event);

    messanger.Register<MouseButtonPressedEvent>(GX_EVENT(OnMouseButtonPressedEvent));
    messanger.Register<MouseButtonReleasedEvent>(GX_EVENT(OnMouseButtonReleasedEvent));
    messanger.Register<MouseMotionEvent>(GX_EVENT(OnMouseMotionEvent));
}

_GX_END