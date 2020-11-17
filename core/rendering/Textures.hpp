/*
// gX Textures API
*/

#ifndef _GX_TEXTURES_
#define _GX_TEXTURES_

#include "core/Common.hpp"

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class Texture {
public:
    virtual ~Texture() = default;

    virtual void Bind(Index _iPos = 0u) const = 0; 

    virtual Program GetProgram() const = 0;
    virtual uInt GetWidth() const = 0;
    virtual uInt GetHeight() const = 0;

};

/**
 * TODO:
 *  Vulkan
 **/
class Texture2D : public Texture {
public:
    static Reference<Texture2D> Create(Vec2 _vSize, const void* _pData);
    static Reference<Texture2D> Create(const char* _sPath);
    
};

_GX_END

#endif