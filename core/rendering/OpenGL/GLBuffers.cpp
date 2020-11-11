/*
// OpenGL Buffers
*/ 
#include "GLBuffers.hpp"
#include <glad/glad.h>

_GX_REGION_BEGIN(OpenGL)

/** Begin VertexBuffer **/

VertexBuffer::VertexBuffer(const std::vector<float>& _aVertices)
{
    /** TODO: Support GL_DYNAMIC_DRAW **/
    glCreateBuffers(1, &m_Program);
    glBindBuffer(GL_ARRAY_BUFFER, m_Program);
    glBufferData(GL_ARRAY_BUFFER, _aVertices.size() * sizeof(float), &_aVertices[0], GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_Program);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Program);
}

void VertexBuffer::SetLayout(const gx::Layout& _aLayout)
{
    m_Layout = _aLayout;
}

gx::Layout& VertexBuffer::GetLayout(void)
{
    return m_Layout;
}

/** End VertexBuffer **/

/** Begin ElementBuffer **/

ElementBuffer::ElementBuffer(const std::vector<gx::Index>& _aElements)
{
    /** TODO: Support GL_DYNAMIC_DRAW? **/
    glCreateBuffers(1, &m_Program);
    glBindBuffer(GL_ARRAY_BUFFER, m_Program);
    glBufferData(GL_ARRAY_BUFFER, _aElements.size() * sizeof(gx::Index), &_aElements[0], GL_STATIC_DRAW); 
}

ElementBuffer::~ElementBuffer()
{
    glDeleteBuffers(1, &m_Program);
}

void ElementBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Program);
}

/** End ElementBuffer **/

_GX_REGION_END