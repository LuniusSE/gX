/*
// Keyboard InputDevice
*/

#include "io/Devices/KeyboardDevice.hpp"

_GX_BEGIN

KeyboardInputDevice::KeyboardInputDevice()
{
}

KeyboardInputDevice::~KeyboardInputDevice()
{
}

bool KeyboardInputDevice::OnKeyPressedEvent(KeyPressedEvent& _Event)
{
    m_KeyStates[_Event.GetKey()] = State::Pressed;

    return false;
}

bool KeyboardInputDevice::OnKeyReleasedEvent(KeyReleasedEvent& _Event)
{
    m_KeyStates[_Event.GetKey()] = State::Released;

    return false;
}

void KeyboardInputDevice::InitializeDevice(void)
{
    ClearDeviceState();
}

void KeyboardInputDevice::ShutdownDevice(void)
{
    ClearDeviceState();
}

void KeyboardInputDevice::ClearDeviceState(void)
{
    for (State& Key : m_KeyStates)
        Key = State::Released;
}

State KeyboardInputDevice::GetInputState(const uInt& _uInputHandle) const
{
    return m_KeyStates[_uInputHandle];
}

float KeyboardInputDevice::GetInputAxis(const uInt& _uInputHandle) const
{
    return 0.0f;
}

bool KeyboardInputDevice::GetInputPressed(const uInt& _uInputHandle) const
{
    return (m_KeyStates[_uInputHandle] == State::Pressed);
}

bool KeyboardInputDevice::GetInputReleased(const uInt& _uInputHandle) const
{
    return (m_KeyStates[_uInputHandle] == State::Released);
}

void KeyboardInputDevice::OnDeviceEvent(Event& _Event)
{
    EventMessanger messanger(_Event);

    messanger.Register<KeyPressedEvent>(GX_EVENT(OnKeyPressedEvent));
    messanger.Register<KeyReleasedEvent>(GX_EVENT(OnKeyReleasedEvent));
}

_GX_END