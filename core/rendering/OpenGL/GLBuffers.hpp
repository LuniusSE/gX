/*
// OpenGL Buffers API
*/

#ifndef _GX_OPENGL_BUFFERS_
#define _GX_OPENGL_BUFFERS_

#include "rendering/Buffers.hpp"
#include "core/Types.hpp"

_GX_REGION_BEGIN(OpenGL)

class VertexBuffer : public gx::VertexBuffer {
private:
    gx::Program m_Program;
    gx::Layout m_Layout;

public:
    VertexBuffer(gx::Size _uSize);
    VertexBuffer(const void* _pVertices, gx::Size _uSize);
    ~VertexBuffer();

    virtual void Bind() const override;

    virtual void SetLayout(const gx::Layout& _aLayout) override;
    virtual gx::Layout& GetLayout(void) override;
    virtual void SetBufferData(const void* _pData, gx::Size _uSize) override;

};

class ElementBuffer : public gx::ElementBuffer {
private:
    gx::Program m_Program;

public:
    ElementBuffer(const std::vector<gx::Index>& _aElements);
    ~ElementBuffer();

    virtual void Bind() const override;
};

_GX_REGION_END

#endif