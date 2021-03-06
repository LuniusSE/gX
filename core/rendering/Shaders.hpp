/*
// gX Shaders API
*/

#ifndef _GX_SHADERS_
#define _GX_SHADERS_

#include "core/Common.hpp"
#include "maths/Types.hpp"

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class Shader {
public:
    virtual ~Shader() = default;

    virtual void Bind() const = 0;

    virtual void SetUniformInt(const char* _sUniform, int _nData) = 0;
    virtual void SetUniformIntArray(const char* _sUniform, Count _uCount, const int* _pData) = 0;

    virtual void SetUniformFloat(const char* _sUniform, float _fData) = 0;
    virtual void SetUniformFloat2(const char* _sUniform, const Vec2& _vData) = 0;
    virtual void SetUniformFloat3(const char* _sUniform, const Vec3& _vData) = 0;
    virtual void SetUniformFloat4(const char* _sUniform, const Vec4& _vData) = 0;

    virtual void SetUniformMat2(const char* _sUniform, const Mat2& _vData) = 0;
    virtual void SetUniformMat3(const char* _sUniform, const Mat3& _vData) = 0;
    virtual void SetUniformMat4(const char* _sUniform, const Mat4& _vData) = 0;

    /*! @brief Create a new Shader from source
    **/
    static Reference<Shader> Create(const std::string& _sVertexSource, const std::string& _sFragmentSource);

    /*! @brief Create a new Shader from a file
    **/
    static Reference<Shader> Create(const char* _sPath);
};

_GX_END

#endif