/*
// Virtual InputDevice
*/

#ifndef _GX_IO_INPUT_DEVICE_
#define _GX_IO_INPUT_DEVICE_

/** Includes **/
#include <Common.hpp>
#include "InputEnums.hpp"

_GX_BEGIN

/**
 * 
 **/
class InputDevice
{
public:
    virtual ~InputDevice() = default;

    virtual void InitializeDevice(void) = 0;
    virtual void ShutdownDevice(void) = 0;

    virtual void ClearDeviceState(void) = 0;

    virtual State GetInputState(const uInt& _uInputHandle) const = 0;
    virtual float GetInputAxis(const uInt& _uInputHandle) const = 0;

    virtual bool GetInputPressed(const uInt& _uInputHandle) const = 0;
    virtual bool GetInputReleased(const uInt& _uInputHandle) const = 0;

    virtual void OnDeviceEvent(Event& _Event) = 0;

};

_GX_END

#endif