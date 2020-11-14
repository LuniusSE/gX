/*
// Graphics API
*/

#ifndef _GX_RENDERING_API_
#define _GX_RENDERING_API_

/** Headers **/
#include <Common.hpp>
#include "Arrays.hpp"

_GX_BEGIN

/** Graphics API **/
enum class API
{
    None = 0,

    OpenGL,
    Vulkan
};

/**
 * TODO:
 *  Vulkan
 **/
class GraphicsAPI
{
public:
    static API s_API;

public:
    ~GraphicsAPI() = default;

    virtual void SetViewport(const Vec2& _vViewport) const = 0;
    virtual void SetClearColour(const Vec4& _vClearColour) const = 0;

    virtual void Clear() const = 0;
    virtual void DrawIndexed(Reference<VertexArray>& _pVertexArray, Count _nElementCount) const = 0;

    virtual void ResetTextures() const = 0;
    virtual void ResetShaders() const = 0;
    virtual void ResetVertexBuffers() const = 0;
    virtual void ResetElementBuffers() const = 0;
    virtual void ResetVertexArrays() const = 0;

    /*! @brief Create a new GraphicsAPI instance
    **/
    static Scope<GraphicsAPI> Create();
};

_GX_END

#endif