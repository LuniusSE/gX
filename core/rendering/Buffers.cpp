/*
// gX Graphics Buffers API
*/

#include "rendering/Buffers.hpp"
#include "rendering/OpenGL/GLBuffers.hpp"

_GX_BEGIN

Reference<VertexBuffer> VertexBuffer::Create(Size _uSize)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexBuffer>(_uSize);
}

Reference<VertexBuffer> VertexBuffer::Create(const void* _pVertices, Size _uSize)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexBuffer>(_pVertices, _uSize);
}

Reference<ElementBuffer> ElementBuffer::Create(const std::vector<Index>& _aElements)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::ElementBuffer>(_aElements);
}

_GX_END