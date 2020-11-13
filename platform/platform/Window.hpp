/*
// Platform Window
*/

#ifndef _GX_PLATFORM_WINDOW_HEADER_
#define _GX_PLATFORM_WINDOW_HEADER_

/** Headers **/
#include <Common.hpp>
#include "Context.hpp"
#include <string>

_GX_BEGIN 
_GX_REGION_BEGIN(Platform)

/**
 * TODO:
 *  X11
 *  WinApi
 *  Wayland
 **/
class Window
{
public:
    virtual ~Window() = default;

    virtual bool IsOpen() const = 0;

    virtual uInt GetWidth() const = 0;
    virtual uInt GetHeight() const = 0;
    virtual Context* GetContext() const = 0;

    virtual void Update() = 0;

    static Scope<Window> Create(const std::string& _sTitle, uInt _nWidth, uInt _nHeight); 

};

_GX_REGION_END
_GX_END

#endif