/*
// 2D Renderer
*/

#ifndef _GX_RENDERING_RENDERER2D_
#define _GX_RENDERING_RENDERER2D_

/** Headers **/
#include <Common.hpp>
#include "Textures.hpp"
#include <maths/Orthographic.hpp>


_GX_BEGIN

class Renderer2D
{
private:
    static void StartBatch();
    static void NextBatch();

public:

    /*! @brief Initialize Renderer2D data
    **/
    static void Initialize();

    /*! @brief Free Renderer2D data
    **/
    static void Shutdown();

    /*! @brief Start a new scene
    **/
    static void BeginScene(Orthographic& _Projection);

    /*! @brief Start a new scene
    **/
    static void EndScene();

    /*! @brief Flushes batch data
    **/
    static void Flush();

    /*! @brief Build Quad
    **/
    static void BuildQuad(const Mat4& _mTransform, const Vec2& _vTiling, const Vec4& _vTint, const Int& _nTextureIndex);

    /*! @brief Render a new Quad with a Texture
    **/
    static void RenderQuad(const Mat4& _mTransform, const Vec2& _vTiling, const Vec4& _vTint, Reference<Texture2D>& _pTexture);

};

_GX_END

#endif