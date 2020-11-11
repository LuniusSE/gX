/*
// OpenGL Shaders
*/

#ifndef _GX_RENDERING_GLSHADERS_HEADER_
#define _GX_RENDERING_GLSHADERS_HEADER_

/** Headers **/
#include <rendering/Shaders.hpp>

_GX_REGION_BEGIN(OpenGL)

class Shader : public gx::Shader
{
public:
    Shader(const std::string& _sVertexSource, const std::string& _sFragmentSource);
    Shader(const char* _sPath);
    ~Shader();
};

_GX_REGION_END

#endif