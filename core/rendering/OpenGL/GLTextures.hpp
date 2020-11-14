/*
// OpenGL Textures
*/

#ifndef _GX_RENDERING_GLTEXTURES_
#define _GX_RENDERING_GLTEXTURES_

/** Headers **/
#include <rendering/Textures.hpp>
#include <string>

_GX_REGION_BEGIN(OpenGL)

class Texture2D : public gx::Texture2D
{
private:
    gx::Program m_Program;
    std::string m_Path;

    gx::uInt m_Width, m_Height, m_Channels;

    void CreateTextureFromData(const gx::uChar* _pData);
    void CreateTextureFromFile();

public:
    Texture2D(gx::Vec2 _vSize, const gx::uChar* _pData);
    Texture2D(const char* _sPath);
    ~Texture2D();

    virtual void Bind(gx::Index _iPos = 0u) const override; 

	virtual gx::uInt GetWidth() const override;
	virtual gx::uInt GetHeight() const override;

};

_GX_REGION_END

#endif