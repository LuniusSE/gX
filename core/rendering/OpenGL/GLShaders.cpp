/*
// OpenGL Shaders
*/ 
#include "GLShaders.hpp"
#include <glad/glad.h>

_GX_REGION_BEGIN(OpenGL)

Shader::Shader(const std::string& _sVertexSource, const std::string& _sFragmentSource)
    : m_Vertex(_sVertexSource), m_Fragment(_sFragmentSource)
{
    CreateShader();
}

Shader::Shader(const char* _sPath)
{
    /** TODO: Read File **/
    // gx::File ShaderFile;
    // gx::OpenFile(ShaderFile, gx::FileOptions::Read);
    // m_Vertex = gx::ReadRegion(ShaderFile, "Vertex");
    // m_Fragment = gx::ReadRegion(ShaderFile, "Fragment");

    // CreateShader();
}

Shader::~Shader()
{
    glDeleteProgram(m_Program);
}

void Shader::CreateShader()
{
    /** Create Shader Program **/
    m_Program = glCreateProgram();

    /** Create Vertex **/
    gx::Program VertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char* VertexSource = m_Vertex.c_str();
    glShaderSource(VertexShader, 1, &VertexSource, nullptr);
    glCompileShader(VertexShader);

    /** Error check Vertex source **/
    int VertexStatus;
    glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &VertexStatus);

    /** If failed to compile the Vertex shader **/
    if (VertexStatus == 0)
    {
        int OutputLength;
        glGetShaderiv(VertexShader, GL_INFO_LOG_LENGTH, &OutputLength);

        std::string Output(OutputLength, '\n');
        glGetShaderInfoLog(VertexShader, OutputLength, &OutputLength, &Output[0]);

        /** TODO: Replace with actual debugging **/
        printf("[TEMP] GLSL Vertex:\n%s\n", Output.c_str());
    }

    /** Create Fragment **/
    gx::Program FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* FragmentSource = m_Fragment.c_str();
    glShaderSource(FragmentShader, 1, &FragmentSource, nullptr);
    glCompileShader(FragmentShader);

    /** Error check Fragment source **/
    int FragmentStatus;
    glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &FragmentStatus);

    /** If failed to compile the Fragment shader **/
    if (FragmentStatus == 0)
    {
        int OutputLength;
        glGetShaderiv(FragmentShader, GL_INFO_LOG_LENGTH, &OutputLength);

        std::string Output(OutputLength, '\n');
        glGetShaderInfoLog(FragmentShader, OutputLength, &OutputLength, &Output[0]);

        /** TODO: Replace with actual debugging **/
        printf("[TEMP] GLSL Fragment:\n%s\n", Output.c_str());
    }

    /** Attach Shaders **/
    glAttachShader(m_Program, VertexShader);
    glAttachShader(m_Program, FragmentShader);
    glLinkProgram(m_Program);

    /** Delete Shaders **/
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}

void Shader::Bind() const
{
    glUseProgram(m_Program);
}

gx::uInt Shader::GetLocation(const char* _sUniform)
{
    return glGetUniformLocation(m_Program, _sUniform);
}

void Shader::SetUniformInt(const char* _sUniform, int _nData)
{
    glUniform1i(GetLocation(_sUniform), _nData);
}

void Shader::SetUniformIntArray(const char* _sUniform, gx::Count _uCount, const int* _pData)
{
    glUniform1iv(GetLocation(_sUniform), (GLsizei)_uCount, _pData);
}

void Shader::SetUniformFloat(const char* _sUniform, float _fData)
{
    glUniform1f(GetLocation(_sUniform), _fData);
}

void Shader::SetUniformFloat2(const char* _sUniform, const gx::Vec2& _vData)
{
    glUniform2f(GetLocation(_sUniform), _vData.x, _vData.y);
}

void Shader::SetUniformFloat3(const char* _sUniform, const gx::Vec3& _vData)
{
    glUniform3f(GetLocation(_sUniform), _vData.x, _vData.y, _vData.z);
}

void Shader::SetUniformFloat4(const char* _sUniform, const gx::Vec4& _vData)
{
    glUniform4f(GetLocation(_sUniform), _vData.x, _vData.y, _vData.z, _vData.w);
}

void Shader::SetUniformMat2(const char* _sUniform, const gx::Mat2& _vData)
{
    glUniformMatrix2fv(GetLocation(_sUniform), 1, GL_FALSE, glm::value_ptr(_vData));
}

void Shader::SetUniformMat3(const char* _sUniform, const gx::Mat3& _vData)
{
    glUniformMatrix3fv(GetLocation(_sUniform), 1, GL_FALSE, glm::value_ptr(_vData));
}

void Shader::SetUniformMat4(const char* _sUniform, const gx::Mat4& _vData)
{
    glUniformMatrix4fv(GetLocation(_sUniform), 1, GL_FALSE, glm::value_ptr(_vData));
}

_GX_REGION_END