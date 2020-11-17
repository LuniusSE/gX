/*
// OpenGL GraphicsAPI
*/

#include "rendering/OpenGL/GLApi.hpp"
#include "glad/glad.h"

#include <stdio.h>

_GX_REGION_BEGIN(OpenGL)

static void OpenGLCallback(
    unsigned, unsigned,
    unsigned, unsigned, int,
    const char* message,
    const void*)
    { printf("[TEMP] OpenGL\n%s\n", message); }

GraphicsAPI::GraphicsAPI()
{
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(OpenGLCallback, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_FALSE);
}

GraphicsAPI::~GraphicsAPI()
{
}

void GraphicsAPI::SetViewport(const gx::Vec2& _vViewport) const
{
    glViewport(0, 0, _vViewport.x, _vViewport.y);
}

void GraphicsAPI::SetClearColour(const gx::Vec4& _vClearColour) const
{
    glClearColor(_vClearColour.r, _vClearColour.g, _vClearColour.b, _vClearColour.a);
}

void GraphicsAPI::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsAPI::DrawIndexed(gx::Reference<gx::VertexArray>& _pVertexArray, gx::Count _nElementCount) const
{
    _pVertexArray->Bind();
    glDrawElements(GL_TRIANGLES, _nElementCount, GL_UNSIGNED_INT, nullptr);
}

void GraphicsAPI::ResetTextures() const
{
}

void GraphicsAPI::ResetShaders() const
{
    glUseProgram(0u);
}

void GraphicsAPI::ResetVertexBuffers() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0u);
}

void GraphicsAPI::ResetElementBuffers() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
}

void GraphicsAPI::ResetVertexArrays() const
{
    glBindVertexArray(0u);
}

_GX_REGION_END