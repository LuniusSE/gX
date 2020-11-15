/*
// Keyboard InputDevice
*/

#ifndef _GX_IO_INPUT_DEVICE_KEYBOARD_
#define _GX_IO_INPUT_DEVICE_KEYBOARD_

/** Includes **/
#include <io/Input.hpp>

/** Temp **/
#include <glfw/glfw3.h>

_GX_BEGIN

/**
 * 
 **/
class KeyboardInputDevice : public InputDevice
{
private:
    State m_KeyStates[GLFW_KEY_LAST];

    bool OnKeyPressedEvent(KeyPressedEvent& _Event);
    bool OnKeyReleasedEvent(KeyReleasedEvent& _Event);

public:
    KeyboardInputDevice();
    ~KeyboardInputDevice();

    virtual void InitializeDevice(void) override;
    virtual void ShutdownDevice(void) override;

    virtual void ClearDeviceState(void) override;

    virtual State GetInputState(const uInt& _uInputHandle) const override;
    virtual float GetInputAxis(const uInt& _uInputHandle) const override;

    virtual bool GetInputPressed(const uInt& _uInputHandle) const override;
    virtual bool GetInputReleased(const uInt& _uInputHandle) const override;

    virtual void OnDeviceEvent(Event& _Event) override;

};

_GX_END

#endif