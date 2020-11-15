/*
// Mouse InputDevice
*/

#ifndef _GX_IO_INPUT_DEVICE_MOUSE_
#define _GX_IO_INPUT_DEVICE_MOUSE_

/** Includes **/
#include <io/Input.hpp>

/** Temp **/
#include <glfw/glfw3.h>

_GX_BEGIN

/**
 * 
 **/
class MouseInputDevice : public InputDevice
{
private:
    State m_ButtonStates[GLFW_MOUSE_BUTTON_LAST];
    float m_MouseX, m_MouseY;

    bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& _Event);
    bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& _Event);
    bool OnMouseMotionEvent(MouseMotionEvent& _Event);

public:
    MouseInputDevice();
    ~MouseInputDevice();

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