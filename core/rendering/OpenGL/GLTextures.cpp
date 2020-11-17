/*
// OpenGL Textures API
*/ 

#include "rendering/OpenGL/GLTextures.hpp"
#include "glad/glad.h"
#include "stb/stb_image.h"

_GX_REGION_BEGIN(OpenGL)

Texture2D::Texture2D(gx::Vec2 _vSize, const void* _pData)
    : m_Width(_vSize.x), m_Height(_vSize.y)
{
    CreateTextureFromData(_pData);
}

Texture2D::Texture2D(const char* _sPath)
    : m_Path(_sPath)
{
    CreateTextureFromFile();
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &m_Program);
}

void Texture2D::CreateTextureFromData(const void* _pData)
{
    /** Create Texture **/
    glCreateTextures(GL_TEXTURE_2D, 1, &m_Program);
    glTextureStorage2D(m_Program, 1, GL_RGBA8, m_Width, m_Height);

    /** Texture Options **/
    glTextureParameteri(m_Program, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(m_Program, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(m_Program, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTextureParameteri(m_Program, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /** Set Texture data **/
    glTextureSubImage2D(m_Program, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, _pData);
}

void Texture2D::CreateTextureFromFile()
{
    /** Flip **/
    stbi_set_flip_vertically_on_load(1);

    /** Load Image **/
    int tempw, temph, tempc;
    stbi_uc* Image = stbi_load(m_Path.c_str(), &tempw, &temph, &tempc, 0);

    /** Error check loading the image **/
    if(Image == NULL)
    {
        printf("[TEMP] STBI %s:\n%s\n", m_Path.c_str(), stbi_failure_reason());
        return;
    }

    /** Set Variables **/
    m_Width = (gx::uInt)tempw;
    m_Height = (gx::uInt)temph;
    m_Channels = (gx::uInt)tempc;

    /** Determine Format **/
    // gx::uInt internalFormat, format;

    /** Create Texture **/
    glCreateTextures(GL_TEXTURE_2D, 1, &m_Program);
    glTextureStorage2D(m_Program, 1, GL_RGB8, m_Width, m_Height);

    /** Texture Options **/
    glTextureParameteri(m_Program, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(m_Program, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(m_Program, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTextureParameteri(m_Program, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /** Set Texture data **/
    glTextureSubImage2D(m_Program, 0, 0, 0, m_Width, m_Height, GL_RGB, GL_UNSIGNED_BYTE, Image);

    /** Free Texture **/
    stbi_image_free(Image);
}
 
void Texture2D::Bind(gx::Index _iPos) const
{
    glActiveTexture(GL_TEXTURE0 + _iPos);
    glBindTexture(GL_TEXTURE_2D, m_Program);
}

gx::Program Texture2D::GetProgram() const
{
    return m_Program;
}

gx::uInt Texture2D::GetWidth() const
{
    return m_Width;
}

gx::uInt Texture2D::GetHeight() const
{
    return m_Height;
}

_GX_REGION_END