/*
// OpenGL Buffers
*/ 
#include "GLBuffers.hpp"
#include <glad/glad.h>

_GX_REGION_BEGIN(OpenGL)

/** Begin VertexBuffer **/

VertexBuffer::VertexBuffer(gx::Size _uSize)
{
    glCreateBuffers(1, &m_Program);
    glBindBuffer(GL_ARRAY_BUFFER, m_Program);
    glBufferData(GL_ARRAY_BUFFER, _uSize, nullptr, GL_DYNAMIC_DRAW);
}

VertexBuffer::VertexBuffer(const void* _pVertices, gx::Size _uSize)
{
    glCreateBuffers(1, &m_Program);
    glBindBuffer(GL_ARRAY_BUFFER, m_Program);
    glBufferData(GL_ARRAY_BUFFER, _uSize, _pVertices, GL_STATIC_DRAW);
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