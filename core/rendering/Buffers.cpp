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
Reference<VertexBuffer> VertexBuffer::Create(Size _uSize)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexBuffer>(_uSize);
}

/**
 * VertexBuffer::Create Implementation
**/
Reference<VertexBuffer> VertexBuffer::Create(const void* _pVertices, Size _uSize)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexBuffer>(_pVertices, _uSize);
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