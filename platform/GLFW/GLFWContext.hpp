/*
// GLFW Context
*/

#ifndef _GX_PLATFORM_GLFW_CONTEXT_HEADER_
#define _GX_PLATFORM_GLFW_CONTEXT_HEADER_

/** Headers **/
#include <Common.hpp>
#include <platform/Context.hpp>
#include "GLFWWindow.hpp"

_GX_REGION_BEGIN(GLFW)

class Context : public gx::Platform::Context
{
private:
    Window* m_Window;
    // GraphicsContext*

public:
    Context(gx::Platform::Window* _pGLFWWindow);
    ~Context();

    virtual void CreateContext() override;
    virtual void SwapBuffers() override;
    virtual gx::Time GetTime() const override;

};

_GX_REGION_END

#endif