/*
// Graphics Arrays
*/
#include "Arrays.hpp"

/** Headers **/
#include "OpenGL/GLArrays.hpp"

_GX_BEGIN

/**
 * VertexArray::Create Implementation
**/
Reference<VertexArray> VertexArray::Create()
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::VertexArray>();
}

_GX_END