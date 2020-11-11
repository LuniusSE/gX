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
Reference<Texture2D> Texture2D::Create(/** Size, Data **/)
{
    /** TODO: Support GraphicsApi **/
    return nullptr;
}

/**
 * Texture2D::CreateFromFile Implementation
**/
Reference<Texture2D> Texture2D::CreateFromFile(const char* _sPath)
{
    /** TODO: Support GraphicsApi **/
    //return CreateRef<OpenGL::Texture2D>(_sPath);
    return nullptr;
}

_GX_END