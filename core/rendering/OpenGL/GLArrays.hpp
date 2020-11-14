/*
// OpenGL Arrays
*/

#ifndef _GX_RENDERING_GLARRAYS_
#define _GX_RENDERING_GLARRAYS_

/** Headers **/
#include <Common.hpp>
#include <rendering/Arrays.hpp>
#include <rendering/Buffers.hpp>

_GX_REGION_BEGIN(OpenGL)

class VertexArray : public gx::VertexArray
{
private:
    gx::Program m_Program;

public:
    VertexArray();
    ~VertexArray();

    virtual void Bind() const override;

    virtual void AttachVertexBuffer(const gx::Reference<gx::VertexBuffer>& _pVertexBuffer) override;
    virtual void AttachElementBuffer(const gx::Reference<gx::ElementBuffer>& _pElementBuffer) override;
};

_GX_REGION_END

#endif