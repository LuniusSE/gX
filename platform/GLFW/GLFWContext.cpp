/*
// GLFW Context
*/

#include "GLFW/GLFWWindow.hpp"
#include "GLFW/GLFWContext.hpp"

_GX_REGION_BEGIN(GLFW)

Context::Context(gx::Platform::Window* _pGLFWWindow)
    : m_Window((Window*)_pGLFWWindow)
{
    glfwInit();
}

void Context::CreateContext() 
{
    glfwMakeContextCurrent(m_Window->m_pWindow);
    gladLoadGL();
} 

Context::~Context()
{
    glfwTerminate();
}

void Context::SwapBuffers()
{
    glfwSwapBuffers(m_Window->m_pWindow);
}

float Context::GetTime() const
{
    return glfwGetTime();
}

_GX_REGION_END