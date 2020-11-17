/*
// OpenGL Arrays API
*/

#include "rendering/OpenGL/GLArrays.hpp"
#include "rendering/OpenGL/GLLayout.hpp"
#include "glad/glad.h"

_GX_REGION_BEGIN(OpenGL)

VertexArray::VertexArray()
{
    glCreateVertexArrays(1, &m_Program);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_Program);
}

void VertexArray::VertexArray::Bind() const
{
    glBindVertexArray(m_Program);
}

void VertexArray::AttachVertexBuffer(const gx::Reference<gx::VertexBuffer>& _pVertexBuffer)
{
    /** Bind both VAO and VBO so OpenGL can attach them. **/
    glBindVertexArray(m_Program);
    _pVertexBuffer->Bind();

    /** Set the VertexBuffer Layout **/
    HandleVertexAttribPointers(_pVertexBuffer->GetLayout());
}

void VertexArray::AttachElementBuffer(const gx::Reference<gx::ElementBuffer>& _pElementBuffer)
{
    /** Bind both VAO and EBO so OpenGL can attach them. **/
    glBindVertexArray(m_Program);
    _pElementBuffer->Bind();
}

_GX_REGION_END