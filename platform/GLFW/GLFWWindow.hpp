/*
// GLFW Window
*/

#ifndef _GX_GLFW_WINDOW_
#define _GX_GLFW_WINDOW_

#include "core/Common.hpp"
#include "platform/Window.hpp"

#include <glad/glad.h>
#include <glfw/glfw3.h>

_GX_REGION_BEGIN(GLFW)

class Window : public gx::Platform::Window {
friend class Context;
private:
    GLFWwindow* m_pWindow;
    gx::Scope<gx::Platform::Context> m_pContext;
    gx::uInt m_Width, m_Height;
    gx::EventHandlerFn m_Handler;

public:
    Window(const std::string& _sTitle, gx::uInt _uWidth, gx::uInt _uHeight);
    ~Window();

    virtual bool IsOpen() const override;

    virtual void SetEventHandler(const gx::EventHandlerFn& _fnHandler) override;
    
    virtual gx::uInt GetWidth() const override;
    virtual gx::uInt GetHeight() const override;
    virtual gx::Platform::Context* GetContext() const override;

    virtual void Update() override;
    
};

_GX_REGION_END

#endif