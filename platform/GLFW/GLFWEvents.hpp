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

/**
 * TODO:
    void GLFW_MouseButtonEvent();
    void GLFW_MouseMotionEvent();
    void GLFW_MOuseScrollEvent();
**/

_GX_REGION_END

#endif