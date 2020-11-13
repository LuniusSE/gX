/*
// GLFW Context
*/
#include "GLFWWindow.hpp"
#include "GLFWContext.hpp"

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

_GX_REGION_END