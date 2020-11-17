/*
// GLFW Context
*/

#ifndef _GX_PLATFORM_GLFWEVENTS_
#define _GX_PLATFORM_GLFWEVENTS_

/** Headers **/
#include <Common.hpp>
#include <glfw/glfw3.h>

_GX_REGION_BEGIN(GLFW)

void GLFW_KeyEvent(GLFWwindow* _pWindow, int _nKey, int _nScancode, int _nAction, int _nMods);

void GLFW_MouseButtonEvent(GLFWwindow* _pWindow, int _nButton, int _nAction, int _nMods);
void GLFW_MouseMotionEvent(GLFWwindow* _pWindow, double _nX, double _nY);
void GLFW_MouseScrollEvent(GLFWwindow* _pWindow, double _nX, double _nY);

void GLFW_WindowCloseEvent(GLFWwindow* _pWindow);
void GLFW_WindowResizedEvent(GLFWwindow* _pWindow, int _nWidth, int _nHeight);

_GX_REGION_END

#endif