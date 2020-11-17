/*
// Input
*/

#include "io/Input.hpp"
#include "io/Devices/KeyboardDevice.hpp"
#include "io/Devices/MouseDevice.hpp"

#include <stdio.h>

_GX_BEGIN

Input::DeviceMap Input::s_Devices;

void Input::RegisterDevice(const char* _sName, InputDevice* _pDevice)
{
    if (s_Devices.find(_sName) != s_Devices.end())
        printf("[Temp] Input\n%s\n", "Tried to overwrite an InputDevice.");

    if (_pDevice == nullptr)
        printf("[Temp] Input\n%s\n", "Tried to register a null InputDevice.");

    s_Devices[_sName].reset(_pDevice);
}

void Input::Initialize()
{
    RegisterDevice("Keyboard", new KeyboardInputDevice);
    RegisterDevice("Mouse", new MouseInputDevice);

    for(auto& pDevice : s_Devices)
        pDevice.second->InitializeDevice();
}

void Input::Shutdown()
{
    for(auto& pDevice : s_Devices)
        pDevice.second->ShutdownDevice();
}

void Input::OnEvent(Event& _Event)
{
    for(auto& pDevice : s_Devices)
        pDevice.second->OnDeviceEvent(_Event);
}

InputDevice* Input::GetDevice(const char* _sName)
{
    if (s_Devices[_sName].get() == nullptr ||
        s_Devices.find(_sName) == s_Devices.end())
    {
        printf("[Temp] Input\n%s\n", "Tried to index a null InputDevice.");
        return nullptr;
    }

    return s_Devices[_sName].get();
}

_GX_END