/*
// GLFW Events
*/

#include "GLFW/GLFWEvents.hpp"

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

void SendButtonPressedEvent(gx::EventHandlerFn& _fnHandler, int _nButton, int _nX, int _nY)
{
    gx::MouseButtonPressedEvent e(_nButton, _nX, _nY);
    _fnHandler(e);
}

void SendButtonReleasedEvent(gx::EventHandlerFn& _fnHandler, int _nButton, int _nX, int _nY)
{
    gx::MouseButtonReleasedEvent e(_nButton, _nX, _nY);
    _fnHandler(e);
}

void SendMotionEvent(gx::EventHandlerFn& _fnHandler, int _nX, int _nY)
{
    gx::MouseMotionEvent e(_nX, _nY);
    _fnHandler(e);
}

void SendScrollEvent(gx::EventHandlerFn& _fnHandler, float _nX, float _nY)
{
    gx::MouseScrollEvent e(_nY);
    _fnHandler(e);
}

void SendWindowCloseEvent(gx::EventHandlerFn& _fnHandler)
{
    gx::WindowClosedEvent e;
    _fnHandler(e);
}

void SendResizedEvent(gx::EventHandlerFn& _fnHandler, int _nWidth, int _nHeight)
{
    gx::WindowResizedEvent e(_nWidth, _nHeight);
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

void GLFW_MouseButtonEvent(GLFWwindow* _pWindow, int _nButton, int _nAction, int _nMods)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));

    double nX, nY;
    glfwGetCursorPos(_pWindow, &nX, &nY);

    switch (_nAction)
    {
    case GLFW_REPEAT:
    {
        SendButtonPressedEvent(eHandler, _nButton, nX, nY);
        break;
    }
    case GLFW_PRESS:
    {
        SendButtonPressedEvent(eHandler, _nButton, nX, nY);
        break;
    }
    case GLFW_RELEASE:
    {
        SendButtonReleasedEvent(eHandler, _nButton, nX, nY);
        break;
    }
    default: break;
    }
}

void GLFW_MouseMotionEvent(GLFWwindow* _pWindow, double _nX, double _nY)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));

    SendMotionEvent(eHandler, _nX, _nY);
}

void GLFW_MouseScrollEvent(GLFWwindow* _pWindow, double _nX, double _nY)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));

    SendScrollEvent(eHandler, _nX, _nY);
}

void GLFW_WindowCloseEvent(GLFWwindow* _pWindow)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));

    SendWindowCloseEvent(eHandler);
}

void GLFW_WindowResizedEvent(GLFWwindow* _pWindow, int _nWidth, int _nHeight)
{
    gx::EventHandlerFn& eHandler = *static_cast<gx::EventHandlerFn*>(glfwGetWindowUserPointer(_pWindow));

    SendResizedEvent(eHandler, _nWidth, _nHeight);
}

_GX_REGION_END