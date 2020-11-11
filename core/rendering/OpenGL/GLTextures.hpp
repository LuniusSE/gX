/*
// OpenGL Textures
*/

#ifndef _GX_RENDERING_GLTEXTURES_HEADER_
#define _GX_RENDERING_GLTEXTURES_HEADER_

/** Headers **/
#include <rendering/Textures.hpp>

_GX_REGION_BEGIN(OpenGL)

class Texture2D : public gx::Texture2D
{
public:
    Texture2D(const char* _sPath);
    ~Texture2D();
    
};

_GX_REGION_END

#endif