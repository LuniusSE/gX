//
// Write Games Not Game Engines
//

/** Graphics Includes **/
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/** Lua Includes **/
#include <lua.hpp>

/** Other Thirdparty Includes **/
#include <stb/stb_image.hpp>

/** Standard Includes **/
#include <string>

/**         Debug Macros            **/
#define DebugPrint(A, M)            printf("%s\t\t %s:%d %s\n", A, __FUNCTION__, __LINE__, M)

/**         OpenGL Helpers          **/

/**
 * TODO:
 *  VBO
 *  VAO
 *  EBO
 **/

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

/** Main **/
int main()
{
    /** Initialize GLFW **/
    if (glfwInit() == GLFW_FALSE)
    {
        DebugPrint("GLFW", "Failed to initialize.");
        return -1;
    }
    
    /** Set GLFW Error Callback **/
    glfwSetErrorCallback(GLFWCallback);

    /** Create a GLFW Window **/
    GLFWwindow* glfwWindow = glfwCreateWindow(1024, 512, "Write Games Not Game Engines", nullptr, nullptr);
    glfwMakeContextCurrent(glfwWindow);

    /** Error Check **/
    if (!glfwWindow)
    {
        DebugPrint("GLFW", "Failed to create a Window.");
        return -1;
    }

    /** Initialize GLEW **/
    if (glewInit() != GLEW_OK)
    {
        DebugPrint("GLEW", "Failed to initialize.");
        return -1;
    }

    DebugPrint("GLFW", "Window created.");

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
    GLuint QuadVAO = 0u;
    glCreateVertexArrays(1, &QuadVAO);

    /** Quad Vertex Buffer Object **/
    GLuint QuadVBO = 0u;
    glCreateBuffers(1, &QuadVBO);

    /** Quad Element Buffer Object **/
    GLuint QuadEBO = 0u;
    glCreateBuffers(1, &QuadEBO);

    DebugPrint("GLEW", "GL Objects initialized.");
    
    /** Create VAO **/
    glBindVertexArray(QuadVAO);

    /** Create VBO **/
    glBindBuffer(GL_ARRAY_BUFFER, QuadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertices), QuadVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0u, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0u);

    glVertexAttribPointer(1u, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1u);

    /** Create EBO **/
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QuadEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(QuadIndices), QuadIndices, GL_STATIC_DRAW); 

    /** Unbind Quad VAO before loop **/
    glBindVertexArray(0u);

    DebugPrint("GLEW", "GL Objects created.");

    /** Time it took between updates **/
    float LastUpdateTime = 0.0f;
    float DeltaTime = 0.0f;

    /** Define Shaders **/
    const char* VertS = R"(
        #version 440 core

        layout (location = 0) in vec3 Position;
        layout (location = 1) in vec2 TexCoord;

        out vec2 oTexCoord;

        void main()
        {
            gl_Position = vec4(Position, 1.0f);
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
        Shader BasicShader(VertS, FragS);

        /** Create Texture **/
        Texture BasicTexture("sandbox/resources/Image.png");

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

            /** Simple Scene **/
            { /** Begin **/

                /** Bind Texture **/
                BasicTexture.Bind();

                /** Bind Shader **/
                BasicShader.Bind();

                /** Set Shader Uniforms **/
                BasicShader.SetUniformInt("uTexture", 0);
                BasicShader.SetUniformFloat4("uTint", 1.0f, 0.3f, 0.6f, 1.0f);

                /** Render Quad **/
                glBindVertexArray(QuadVAO);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            } /** End **/

            /** Swap GLFW Window Buffers **/
            glfwSwapBuffers(glfwWindow);
        }

    }

    /** Destroy OpenGL Objects **/
    glDeleteBuffers(1, &QuadVBO);
    glDeleteBuffers(1, &QuadEBO);
    glDeleteVertexArrays(1, &QuadVAO);

    DebugPrint("GLEW", "GL Objects destroyed.");

    /** Destroy the GLFW Window **/
    glfwDestroyWindow(glfwWindow);

    DebugPrint("GLFW", "Window Destroyed.");

    /** Shutdown GLFW **/
    glfwTerminate();

    return 0;
}