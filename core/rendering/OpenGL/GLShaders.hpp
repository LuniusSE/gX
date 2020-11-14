/*
// OpenGL Shaders
*/

#ifndef _GX_RENDERING_GLSHADERS_
#define _GX_RENDERING_GLSHADERS_

/** Headers **/
#include <rendering/Shaders.hpp>
#include <string>

_GX_REGION_BEGIN(OpenGL)

class Shader : public gx::Shader
{
private:
    gx::Program m_Program;
    std::string m_Vertex, m_Fragment;

    void CreateShader();

public:
    Shader(const std::string& _sVertexSource, const std::string& _sFragmentSource);
    Shader(const char* _sPath);
    ~Shader();

    virtual void Bind() const override;

    gx::uInt GetLocation(const char* _sUniform);

    virtual void SetUniformInt(const char* _sUniform, int _nData) override;
    virtual void SetUniformIntArray(const char* _sUniform, gx::Count _uCount, const int* _pData) override;

    virtual void SetUniformFloat(const char* _sUniform, float _fData) override;
    virtual void SetUniformFloat2(const char* _sUniform, const gx::Vec2& _vData) override;
    virtual void SetUniformFloat3(const char* _sUniform, const gx::Vec3& _vData) override;
    virtual void SetUniformFloat4(const char* _sUniform, const gx::Vec4& _vData) override;

    virtual void SetUniformMat2(const char* _sUniform, const gx::Mat2& _vData) override;
    virtual void SetUniformMat3(const char* _sUniform, const gx::Mat3& _vData) override;
    virtual void SetUniformMat4(const char* _sUniform, const gx::Mat4& _vData) override;
    
};

_GX_REGION_END

#endif