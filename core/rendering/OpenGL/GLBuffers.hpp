/*
// OpenGL Buffers
*/

#ifndef _GX_RENDERING_GLBUFFERS_HEADER_
#define _GX_RENDERING_GLBUFFERS_HEADER_

/** Headers **/
#include <rendering/Buffers.hpp>
#include <Types.hpp>

_GX_REGION_BEGIN(OpenGL)

class VertexBuffer : public gx::VertexBuffer
{
public:
    VertexBuffer(const std::vector<float>& _aVertices);
    ~VertexBuffer();
};

class ElementBuffer : public gx::ElementBuffer
{
public:
    ElementBuffer(const std::vector<gx::Index>& _aElements);
    ~ElementBuffer();
};

_GX_REGION_END

#endif