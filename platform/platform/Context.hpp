/*
// Platform Context
*/

#ifndef _GX_PLATFORM_CONTEXT_HEADER_
#define _GX_PLATFORM_CONTEXT_HEADER_

/** Headers **/
#include <Common.hpp>

_GX_BEGIN 
_GX_REGION_BEGIN(Platform)

/**
 * TODO:
 *  X11
 *  WinApi
 *  Wayland
 * TODO: Inherit from gx::PlatformContext
 **/
class Context
{
public:
    virtual ~Context() = default;

    virtual void CreateContext() = 0;
    virtual void SwapBuffers() = 0;

};

_GX_REGION_END
_GX_END

#endif