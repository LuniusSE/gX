/*
// Graphics Buffers
*/
#include "Buffers.hpp"

/** Headers **/
#include "OpenGL/GLBuffers.hpp"

_GX_BEGIN

/**
 * VertexBuffer::Create Implementation
**/
Reference<VertexBuffer> VertexBuffer::Create(const std::vector<float>& _aVertices)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexBuffer>(_aVertices);
}

/**
 * ElementBuffer::Create Implementation
**/
Reference<ElementBuffer> ElementBuffer::Create(const std::vector<Index>& _aElements)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::ElementBuffer>(_aElements);
}

_GX_END