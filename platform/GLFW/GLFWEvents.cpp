/*
// GLFW Events
*/
#include "GLFWEvents.hpp"
#include <functional>

_GX_REGION_BEGIN(GLFW)

void SendKeyPressEvent(gx::EventHandlerFn& _fnHandler, int _nKey, unsigned _uRepeating)
{
    gx::KeyPressedEvent e(_nKey, _uRepeating);
    _fnHandler(e);
}

void SendKeyReleaseEvent(gx::EventHandlerFn& _fnHandler, int _nKey)
{
    gx::KeyReleasedEvent e(_nKey);
    _fnHandler(e);
}

void SendCharEvent(gx::EventHandlerFn& _fnHandler, char _bChar)
{
    gx::CharEvent e(_bChar);
    _fnHandler(e);
}

void GLFW_KeyEvent(GLFWwindow* _pWindow, int _nKey, int _nScancode, int _nAction, int _nMods)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));
    
    switch (_nAction)
    {
    case GLFW_REPEAT:
    {
        SendKeyPressEvent(eHandler, _nKey, 1u);
        break;
    }
    case GLFW_PRESS:
    {
        SendKeyPressEvent(eHandler, _nKey, 0u);
        break;
    }
    case GLFW_RELEASE:
    {
        SendKeyReleaseEvent(eHandler, _nKey);
        break;
    }
    default: break;
    }
}

_GX_REGION_END