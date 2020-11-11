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
private:
    gx::Program m_Program;
    gx::Layout m_Layout;

public:
    VertexBuffer(const std::vector<float>& _aVertices);
    ~VertexBuffer();

    virtual void Bind() const override;

    virtual void SetLayout(const gx::Layout& _aLayout) override;
    virtual gx::Layout& GetLayout(void) override;

};

class ElementBuffer : public gx::ElementBuffer
{
private:
    gx::Program m_Program;

public:
    ElementBuffer(const std::vector<gx::Index>& _aElements);
    ~ElementBuffer();

    virtual void Bind() const override;
};

_GX_REGION_END

#endif