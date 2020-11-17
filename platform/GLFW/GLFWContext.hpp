/*
// GLFW Context
*/

#ifndef _GX_GLFW_CONTEXT_
#define _GX_GLFW_CONTEXT_

#include "core/Common.hpp"
#include "platform/Context.hpp"
#include "GLFW/GLFWWindow.hpp"

_GX_REGION_BEGIN(GLFW)

class Context : public gx::Platform::Context {
private:
    Window* m_Window;
    // GraphicsContext*

public:
    Context(gx::Platform::Window* _pGLFWWindow);
    ~Context();

    virtual void CreateContext() override;
    virtual void SwapBuffers() override;
    virtual float GetTime() const override;

};

_GX_REGION_END

#endif