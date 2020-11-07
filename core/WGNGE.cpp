//
// Write Games Not Game Engines
//

/** Graphics Includes **/
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/** Lua Includes **/
#include <lua.hpp>

/** GLM Includes **/
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/** Other Thirdparty Includes **/
#include <stb/stb_image.hpp>

/** gX **/
#include "maths/Orthographic.hpp"

/** Standard Includes **/
#include <string>
#include <vector>

/**         Debug Macros            **/
#define DebugPrint(A, M)            printf("%s\t\t %s:%d %s\n", A, __FUNCTION__, __LINE__, M)

/**         OpenGL Helpers          **/

/**
 * Simple OpenGL shader class
 **/
class Shader
{
private:
    GLuint m_ShaderProgram;

    const char* m_sVertexS,
              * m_sFragmentS;
    
    inline void __Create()
    {
        /** Create Shader Program **/
        m_ShaderProgram = glCreateProgram();

        /** Create Vertex **/
        GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(VertexShader, 1, &m_sVertexS, nullptr);
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

            DebugPrint("GLSL", Output.c_str());
        }

        /** Create Fragment **/
        GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(FragmentShader, 1, &m_sFragmentS, nullptr);
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

            DebugPrint("GLSL", Output.c_str());
        }

        /** Attach Shaders **/
        glAttachShader(m_ShaderProgram, VertexShader);
        glAttachShader(m_ShaderProgram, FragmentShader);
        glLinkProgram(m_ShaderProgram);

        /** Delete Shaders **/
        glDeleteShader(VertexShader);
        glDeleteShader(FragmentShader);
    }

    inline void __Destroy()
    {
        glDeleteProgram(m_ShaderProgram);
    }

public:
    Shader(const char* _sVertex, const char* _sFragment)
        :   m_ShaderProgram(0u),
            m_sVertexS(_sVertex), m_sFragmentS(_sFragment)
    {
        __Create();
    }

    ~Shader()
    {
        __Destroy();
    }

    inline void SetUniformInt(const char* _sUniform, int _nInt)
    {
        glUniform1i(glGetUniformLocation(m_ShaderProgram, _sUniform), _nInt);
    }

    inline void SetUniformFloat4(const char* _sUniform, float _fR, float _fG, float _fB, float _fA)
    {
        glUniform4f(glGetUniformLocation(m_ShaderProgram, _sUniform), _fR, _fG, _fB, _fA);
    }

    inline void SetUniformMat4(const char* _sUniform, const glm::mat4& _fMatrix4x4)
    {
        glUniformMatrix4fv(glGetUniformLocation(m_ShaderProgram, _sUniform), 1, GL_FALSE, glm::value_ptr(_fMatrix4x4));
    }

    inline void Bind()
    {
        /** Bind the Shader **/
        glUseProgram(m_ShaderProgram);
    }

    inline static void Reset()
    {
        /** Reset to default Shader **/
        glUseProgram(0u);
    }

};

/**
 * Simple OpenGL Texture class
 **/
class Texture
{
private:
    GLuint m_TextureID;

    const char* m_FilePath;

    int m_Channels,
        m_Width,
        m_Height;

    inline void __Create()
    {
        /** Flip **/
        stbi_set_flip_vertically_on_load(1);

        /** Load Image **/
        stbi_uc* Image = stbi_load(m_FilePath, &m_Width, &m_Height, &m_Channels, 0);

        /** Error check loading the image **/
        if(Image == NULL)
        {
            DebugPrint("STBI", "Failed to load image.");
            DebugPrint("STBI", stbi_failure_reason());
            return;
        }

        printf("%s %dx%d %d\n", m_FilePath, m_Width, m_Height, m_Channels);

        /** Create Texture **/
        glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
        glTextureStorage2D(m_TextureID, 1, GL_RGB8, m_Width, m_Height);

        /** Texture Options **/
        glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);

        /** Set Texture data **/
        glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, GL_RGB, GL_UNSIGNED_BYTE, Image);

        /** Free Texture **/
        stbi_image_free(Image);
    }

    inline void __Destroy()
    {
        glDeleteTextures(1, &m_TextureID);
    }

public:
    Texture(const char* _sFilePath)
        : m_FilePath(_sFilePath)
    {
        __Create();
    }

    ~Texture()
    {
        __Destroy();
    }

    inline GLuint Get()
    {
        /** Get the OpenGL Texture ID **/
        return m_TextureID;
    }

    inline void Bind(unsigned _uPosition = 0u)
    {
        /** Bind the Texture **/
        glActiveTexture(GL_TEXTURE0 + _uPosition);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
    }

};

/** OpenGL Message Callback **/
void OpenGLCallback
    (GLenum, GLenum type, GLuint, GLenum severity, GLsizei, const GLchar* message, const void*)
{
    printf("OpenGL: %s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? "ERROR" : "" ), type, severity, message);
}

void GLFWCallback
    (int _nErrorCode, const char* _sDescription)
{
    printf("GLFW: [%d] %s\n", _nErrorCode, _sDescription);
}

/** OpenGL Attribs **/
enum class Attrib
{
    FLOAT,
    FLOAT2,
    FLOAT3,
    FLOAT4
};

unsigned AttribLength(const Attrib& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Length **/
    case Attrib::FLOAT:  return 1;
    case Attrib::FLOAT2: return 2;
    case Attrib::FLOAT3: return 3;
    case Attrib::FLOAT4: return 4;
    default: break;
    }
    return 0u;
}

unsigned AttribTypeSize(const Attrib& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Type Size **/
    case Attrib::FLOAT:
    case Attrib::FLOAT2:
    case Attrib::FLOAT3:
    case Attrib::FLOAT4: 
        return sizeof(float);
    default: break;
    }
    return 0u;
}

unsigned AttribGLenumType(const Attrib& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Type GLenum **/
    case Attrib::FLOAT:
    case Attrib::FLOAT2:
    case Attrib::FLOAT3:
    case Attrib::FLOAT4: 
        return GL_FLOAT;
    default: break;
    }
    return 0u;
}

void HandleVertexAttribPointers(const std::vector<Attrib>& _vAttribs)
{
    /** Declare variables **/
    unsigned uStride = 0u;
    unsigned uIndex = 0u;
    int nOffset = 0u;

    /** Loop through all Attribs in _vAttribs **/
    /** Calculate Stride **/
    for(const Attrib& eAttrib : _vAttribs)
    {
        uStride += AttribLength(eAttrib) * AttribTypeSize(eAttrib);
    }

    /** Loop through all Attribs in _vAttribs **/
    /** Setup VertexAttribPointers **/
    for(const Attrib& eAttrib : _vAttribs)
    {
        /** Fillout VertexAttribPointer **/
        glVertexAttribPointer(uIndex, AttribLength(eAttrib), AttribGLenumType(eAttrib), GL_FALSE, uStride, (void*)(nOffset));
        glEnableVertexAttribArray(uIndex);

        /** Determine next offset **/
        nOffset += AttribLength(eAttrib) * AttribTypeSize(eAttrib);

        /** Increment the attrib index **/
        uIndex++;
    }
}

/**
 * TODO:
 *  VBO
 *  EBO
 **/

class VertexArray
{
private:
    GLuint m_GLid;

    inline void __Create()
    {
        /** Create the VertexArray **/
        glCreateVertexArrays(1, &m_GLid);
    }

    inline void __Destroy()
    {
        /** Delete VertexArray **/
        glDeleteVertexArrays(1, &m_GLid);
    }

public:
    VertexArray()
     : m_GLid(0u)
    {
        __Create();
    }

    ~VertexArray()
    {
        __Destroy();
    }

    inline void AttachVertexBuffer(GLuint _gluVertexBuffer)
    {
        glBindVertexArray(m_GLid);
        glBindBuffer(GL_ARRAY_BUFFER, _gluVertexBuffer);
    }

    inline void AttachElementBuffer(GLuint _gluElementBuffer)
    {
        glBindVertexArray(m_GLid);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _gluElementBuffer);
    }

    inline void Bind()
    {
        /** Bind **/
        glBindVertexArray(m_GLid);
    }

    static inline void Reset()
    {
        /** Unbind the bound VertexArray **/
        glBindVertexArray(0u);
    }

};

/** Main **/
int main()
{
    /** Texture Position **/
    static float X = 0.0f, Y = 0.0f;
    static float Speed = 10.0f;
    
    /** Time it took between updates **/
    static float LastUpdateTime = 0.0f;
    static float DeltaTime = 0.0f;

    /** Initialize GLFW **/
    if (glfwInit() == GLFW_FALSE)
    {
        DebugPrint("GLFW", "Failed to initialize.");
        return -1;
    }
    
    /** Set GLFW Error Callback **/
    glfwSetErrorCallback(GLFWCallback);

    /** Create a GLFW Window **/
    GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "Write Games Not Game Engines", nullptr, nullptr);
    glfwMakeContextCurrent(glfwWindow);
    glfwSwapInterval(1);

    /** Error Check **/
    if (!glfwWindow)
    {
        DebugPrint("GLFW", "Failed to create a Window.");
        return -1;
    }

    /** Initialize GLAD **/
    if (!gladLoadGL())
    {
        DebugPrint("GLAD", "Failed to initialize.");
        return -1;
    }

    DebugPrint("GLFW", "Window created.");

    /** Enable GLFW sticky input **/
    glfwSetInputMode(glfwWindow, GLFW_STICKY_KEYS, GLFW_TRUE);

    /** Set GLFW Callbacks **/
    auto GLFWResize = [](GLFWwindow* _pWindow, int _nWidth, int _nHeight) -> void
    {
        glViewport(0, 0, _nWidth, _nHeight);
    };

    glfwSetFramebufferSizeCallback(glfwWindow, GLFWResize);

    /** Enable OpenGL Debugging **/
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(OpenGLCallback, 0);

    /** Quad Vertices **/
    float       QuadVertices[]  = {
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f
    };

    /** Quad Indices **/
    unsigned    QuadIndices[]   = {
        0u, 1u, 3u,
        1u, 2u, 3u
    };  

    /** Quad Vertex Array Object **/
    VertexArray vertexArray;

    /** Quad Vertex Buffer Object **/
    GLuint QuadVBO = 0u;
    glCreateBuffers(1, &QuadVBO);

    /** Quad Element Buffer Object **/
    GLuint QuadEBO = 0u;
    glCreateBuffers(1, &QuadEBO);

    DebugPrint("GLAD", "GL Objects initialized.");

    /** Create VBO **/
    glBindBuffer(GL_ARRAY_BUFFER, QuadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertices), QuadVertices, GL_STATIC_DRAW);

    vertexArray.AttachVertexBuffer(QuadVBO);

    /** Fillout VertexAttribPointer for given Attribs **/
    HandleVertexAttribPointers({
        Attrib::FLOAT3,
        Attrib::FLOAT2
    });

    /** Create EBO **/
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QuadEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(QuadIndices), QuadIndices, GL_STATIC_DRAW); 

    vertexArray.AttachElementBuffer(QuadEBO);

    /** Unbind Quad VAO before loop **/
    glBindVertexArray(0u);

    DebugPrint("GLAD", "GL Objects created.");

    /** Define Shaders **/
    const char* VertS = R"(
        #version 440 core

        layout (location = 0) in vec3 Position;
        layout (location = 1) in vec2 TexCoord;

        out vec2 oTexCoord;

        uniform mat4 uTransform;
        uniform mat4 uViewProjection;

        void main()
        {
            gl_Position = uViewProjection * uTransform * vec4(Position, 1.0f);
            oTexCoord = TexCoord;
        }

    )";

    const char* FragS = R"(
        #version 440 core

        out vec4 oFragColor;

        in vec2 oTexCoord;

        uniform sampler2D uTexture;
        uniform vec4 uTint;

        void main()
        {
            oFragColor = texture(uTexture, oTexCoord) * uTint;
        }

    )";

    {

        /** Create Shader **/
        Shader BasicShader = Shader(VertS, FragS);

        /** Create Texture **/
        Texture BasicTexture = Texture("sandbox/resources/Image.png");

        /** Orthographic **/
        Orthographic Projection = Orthographic({ 800, 600 }, 10.0f);

        /** Run main loop while the window is open **/
        while(!glfwWindowShouldClose(glfwWindow))
        {
            /** Calculate Delta **/
            float GLFWTime = (float)glfwGetTime();
            DeltaTime = GLFWTime - LastUpdateTime;
            LastUpdateTime = GLFWTime;

            /** FPS: 1.0f / DeltaTime **/
            // printf("Update FPS: %.0f\n", 1.0f / DeltaTime);

            /** Poll Window Events **/
            glfwPollEvents();

            /** Clear OpenGL **/
            glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            /** Input **/
            {

                if (glfwGetKey(glfwWindow, GLFW_KEY_W) != GLFW_RELEASE)
                    Y += Speed * DeltaTime;

                if (glfwGetKey(glfwWindow, GLFW_KEY_A) != GLFW_RELEASE)
                    X -= Speed * DeltaTime;

                if (glfwGetKey(glfwWindow, GLFW_KEY_S) != GLFW_RELEASE)
                    Y -= Speed * DeltaTime;

                if (glfwGetKey(glfwWindow, GLFW_KEY_D) != GLFW_RELEASE)
                    X += Speed * DeltaTime;
                
            }

            /** Quad Transform **/
            glm::mat4 Transform = glm::translate(glm::vec3(X, Y, 0.0f)) * glm::scale(glm::vec3( 7.68f, 3.84f, 1.0f));

            /** Simple Scene **/
            { /** Begin **/

                /** Bind Texture **/
                BasicTexture.Bind();

                /** Bind Shader **/
                BasicShader.Bind();

                /** Set Shader Uniforms **/
                BasicShader.SetUniformMat4("uTransform", Transform);
                BasicShader.SetUniformMat4("uViewProjection", Projection);
                BasicShader.SetUniformInt("uTexture", 0);
                BasicShader.SetUniformFloat4("uTint", 1.0f, 0.3f, 0.3f, 1.0f);

                /** Render Quad **/
                vertexArray.Bind();
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            } /** End **/

            /** Swap GLFW Window Buffers **/
            glfwSwapBuffers(glfwWindow);
        }

    }

    /** Destroy OpenGL Objects **/
    glDeleteBuffers(1, &QuadVBO);
    glDeleteBuffers(1, &QuadEBO);

    DebugPrint("GLAD", "GL Objects destroyed.");

    /** Destroy the GLFW Window **/
    glfwDestroyWindow(glfwWindow);

    DebugPrint("GLFW", "Window Destroyed.");

    /** Shutdown GLFW **/
    glfwTerminate();

    return 0;
}