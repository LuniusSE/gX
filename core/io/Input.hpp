/*
// Input
*/

#ifndef _GX_IO_INPUT_
#define _GX_IO_INPUT_

/** Includes **/
#include <Common.hpp>

#include <string>
#include <unordered_map>

#include "InputDevice.hpp"

_GX_BEGIN

/**
 * 
 **/
class Input
{
public:
    using DeviceMap = std::unordered_map<std::string, Scope<InputDevice>>;

    static DeviceMap s_Devices;

    /*! @brief Register Input device
    **/
    static void RegisterDevice(const char* _sName, InputDevice* _pDevice);

    /*! @brief Initialize InputDevices
    **/
    static void Initialize();

    /*! @brief Shutdown
    **/
    static void Shutdown();

    /*! @brief OnEvent
    **/
    static void OnEvent(Event& _Event);

    /*! @brief Get device pointer
    **/
    static InputDevice* GetDevice(const char* _sName);

};

_GX_END

#endif