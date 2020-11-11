/*
// Graphics Textures
*/

#ifndef _GX_RENDERING_TEXTURESS_HEADER_
#define _GX_RENDERING_TEXTURESS_HEADER_

/** Headers **/
#include <Common.hpp>

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class Texture
{
public:
    virtual ~Texture() = default;

    virtual void Bind(Index _iPos = 0u) const = 0; 
    static void Reset();

	virtual uInt GetWidth() const = 0;
	virtual uInt GetHeight() const = 0;
};

/**
 * TODO:
 *  Vulkan
 **/
class Texture2D : public Texture
{
public:
	static Reference<Texture2D> Create(/** Size, Data **/);
	static Reference<Texture2D> CreateFromFile(const char* _sPath);
};

_GX_END

#endif