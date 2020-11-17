/*
// gX Shaders API
*/

#include "rendering/Shaders.hpp"
#include "rendering/OpenGL/GLShaders.hpp"

_GX_BEGIN

Reference<Shader> Shader::Create(const std::string& _sVertexSource, const std::string& _sFragmentSource)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Shader>(_sVertexSource, _sFragmentSource);
}

Reference<Shader> Shader::Create(const char* _sPath)
{
    /** TODO: Support GraphicsApi **/
    return CreateRef<OpenGL::Shader>(_sPath);
}

_GX_END