/*
// gX Graphics Buffers API
*/

#include "rendering/Arrays.hpp"
#include "rendering/OpenGL/GLArrays.hpp"

_GX_BEGIN

Reference<VertexArray> VertexArray::Create()
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexArray>();
}

_GX_END