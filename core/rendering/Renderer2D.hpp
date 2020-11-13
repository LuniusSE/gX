/*
// 2D Renderer
*/

#ifndef _GX_RENDERING_RENDERER2D_HEADER_
#define _GX_RENDERING_RENDERER2D_HEADER_

/** Headers **/
#include <Common.hpp>
#include <maths/Orthographic.hpp>

_GX_BEGIN

class Renderer2D
{
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

    /*! @brief Render a new Quad
    **/
    static void RenderQuad(const Vec4& _vColour, const Vec3& _vSize, const Vec3& _vPosition);

};

_GX_END

#endif