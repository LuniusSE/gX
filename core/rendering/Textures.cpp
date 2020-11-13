/*
// Graphics Textures
*/
#include "Textures.hpp"

/** Headers **/
#include "OpenGL/GLTextures.hpp"

_GX_BEGIN

/**
 * Texture2D::Create Implementation
**/
Reference<Texture2D> Texture2D::Create(Vec2 _vSize, const uChar* _pData)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Texture2D>(_vSize, _pData);
}

/**
 * Texture2D::CreateFromFile Implementation
**/
Reference<Texture2D> Texture2D::Create(const char* _sPath)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Texture2D>(_sPath);
}

_GX_END