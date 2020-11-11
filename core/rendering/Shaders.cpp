/*
// Graphics Shaders
*/
#include "Shaders.hpp"

/** Headers **/
#include "OpenGL/GLShaders.hpp"

_GX_BEGIN

/**
 * Shader::Create Implementation
**/
Reference<Shader> Create(const std::string& _sVertexSource, const std::string& _sFragmentSource)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Shader>(_sVertexSource, _sFragmentSource);
}

/**
 * Shader::CreateFromFile Implementation
**/
Reference<Shader> CreateFromFile(const char* _sPath)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Shader>(_sPath);
}

_GX_END