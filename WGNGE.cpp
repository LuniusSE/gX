//
// Write Games Not Game Engines
//

/** Graphics Includes **/
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/** Lua Includes **/
#include <lua.hpp>

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

    int Width,
        Height;

    inline void __Create()
    {
        
    }

    inline void __Destroy()
    {

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


};

/** OpenGL Message Callback **/
void GLAPIENTRY OpenGLCallback
    (GLenum, GLenum type, GLuint, GLenum severity, GLsizei, const GLchar* message, const void*)
{
    printf("OpenGL: %s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? "ERROR" : "" ), type, severity, message);
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

    /** Create a GLFW Window **/
    GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "Write Games Not Game Engines", nullptr, nullptr);
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

    /** Enable OpenGL Debugging **/
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(OpenGLCallback, 0);

    /** Quad Vertices **/
    float       QuadVertices[]  = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
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
    glVertexAttribPointer(0u, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0u);

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

        void main()
        {
            gl_Position = vec4(Position, 1.0f);
        }

    )";

    const char* FragS = R"(
        #version 440 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0f, 0.3f, 0.6f, 1.0f);
        }

    )";

    /** Create Shader **/
    Shader BasicShader(VertS, FragS);

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

            /** Bind Shader **/
            BasicShader.Bind();

            /** Render Quad **/
            glBindVertexArray(QuadVAO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QuadEBO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            /** Reset currect OpenGL shader **/
            Shader::Reset();

        } /** End **/

        /** Swap GLFW Window Buffers **/
        glfwSwapBuffers(glfwWindow);
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