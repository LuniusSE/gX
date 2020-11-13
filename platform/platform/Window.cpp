/*
// Platform Window
*/
#include "Window.hpp"

/** Headers **/
#include "GLFW/GLFWWindow.hpp"

_GX_BEGIN
_GX_REGION_BEGIN(Platform)


/**
 * VertexArray::Create Implementation
**/
Scope<Window> Window::Create(const std::string& _sTitle, uInt _nWidth, uInt _nHeight)
{
    /** TODO: Support WinAPI, X11, Wayland **/
    return CreateScope<GLFW::Window>(_sTitle, _nWidth, _nHeight);
}

_GX_REGION_END
_GX_END