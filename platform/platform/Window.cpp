/*
// gX-Core create Window Implementation
*/

#include "platform/Window.hpp"
#include "GLFW/GLFWWindow.hpp"

_GX_BEGIN
_GX_REGION_BEGIN(Platform)

Scope<Window> Window::Create(const std::string& _sTitle, uInt _nWidth, uInt _nHeight)
{
    /** TODO: Support WinAPI, X11, Wayland **/
    return CreateScope<GLFW::Window>(_sTitle, _nWidth, _nHeight);
}

_GX_REGION_END
_GX_END