/*
// GLFW Window
*/

#include "GLFW/GLFWWindow.hpp"
#include "GLFW/GLFWContext.hpp"
#include "GLFW/GLFWEvents.hpp"

_GX_REGION_BEGIN(GLFW)

Window::Window(const std::string& _sTitle, gx::uInt _uWidth, gx::uInt _uHeight)
    : m_Width(_uWidth), m_Height(_uHeight)
{
    m_pContext.reset(new Context(this));
    
    m_pWindow = glfwCreateWindow(m_Width, m_Height, _sTitle.c_str(), nullptr, nullptr);
    if (m_pWindow == nullptr)
    {
        printf("[TEMP] GLFW\n%s\n", "Failed to create GLFWwindow");
    }

    glfwSetWindowUserPointer(m_pWindow, &m_Handler);
    glfwSetKeyCallback(m_pWindow, GLFW_KeyEvent);
    glfwSetMouseButtonCallback(m_pWindow, GLFW_MouseButtonEvent);
    glfwSetCursorPosCallback(m_pWindow, GLFW_MouseMotionEvent);
    glfwSetScrollCallback(m_pWindow, GLFW_MouseScrollEvent);
    glfwSetFramebufferSizeCallback(m_pWindow, GLFW_WindowResizedEvent);
    glfwSetWindowCloseCallback(m_pWindow, GLFW_WindowCloseEvent);

    m_pContext->CreateContext();
}

Window::~Window()
{
    glfwDestroyWindow(m_pWindow);
}

bool Window::IsOpen() const
{
    return (glfwWindowShouldClose(m_pWindow) == 0);
}

void Window::SetEventHandler(const gx::EventHandlerFn& _fnHandler)
{
    m_Handler = _fnHandler;
}

void Window::Update()
{
    glfwPollEvents();
}

gx::uInt Window::GetWidth() const
{
    return m_Width;
}

gx::uInt Window::GetHeight() const
{
    return m_Height;
}

gx::Platform::Context* Window::GetContext() const
{
    return m_pContext.get();
}

_GX_REGION_END