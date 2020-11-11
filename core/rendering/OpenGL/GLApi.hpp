/*
// OpenGL GraphicsAPI
*/

#ifndef _GX_RENDERING_GLAPI_HEADER_
#define _GX_RENDERING_GLAPI_HEADER_

/** Headers **/
#include <Common.hpp>
#include <rendering/GraphicsAPI.hpp>

_GX_REGION_BEGIN(OpenGL)

class GraphicsAPI : public gx::GraphicsAPI
{
public:
    GraphicsAPI();
    ~GraphicsAPI();

    virtual void SetViewport(const gx::Vec2& _vViewport) const override;
    virtual void SetClearColour(const gx::Vec4& _vClearColour) const override;

    virtual void Clear() const override;
    virtual void DrawIndexed(gx::Reference<gx::VertexArray>& _pVertexArray, gx::Count _nElementCount) const override;

    virtual void ResetTextures() const override;
    virtual void ResetShaders() const override;
    virtual void ResetVertexBuffers() const override;
    virtual void ResetElementBuffers() const override;
    virtual void ResetVertexArrays() const override;

};

_GX_REGION_END

#endif