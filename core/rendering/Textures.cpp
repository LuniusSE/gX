/*
// gX Textures API
*/

#include "rendering/Textures.hpp"
#include "rendering/OpenGL/GLTextures.hpp"

_GX_BEGIN

Reference<Texture2D> Texture2D::Create(Vec2 _vSize, const void* _pData)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Texture2D>(_vSize, _pData);
}

Reference<Texture2D> Texture2D::Create(const char* _sPath)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Texture2D>(_sPath);
}

_GX_END