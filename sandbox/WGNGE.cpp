//
// Write Games Not Game Engines
//

/** Graphics Includes **/
#include <glad/glad.h>
#include <glfw/glfw3.h>

/** GLM Includes **/
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/** gX **/
#include <rendering/Shaders.hpp>
#include <rendering/Textures.hpp>
#include <rendering/Arrays.hpp>
#include <rendering/Buffers.hpp>
#include <maths/Orthographic.hpp>
#include <system/Pointers.hpp>
#include <system/Files.hpp>

/** Standard Includes **/
#include <string>
#include <vector>

/**         Debug Macros            **/
#define DebugPrint(A, M)            printf("%s\t\t %s:%d %s\n", A, __FUNCTION__, __LINE__, M)

/** OpenGL Message Callback **/
void OpenGLCallback
    (GLenum, GLenum type, GLuint, GLenum severity, GLsizei, const GLchar* message, const void*)
{
    printf("OpenGL\t\t [%d] %s\n", type, message);
}

void GLFWCallback
    (int _nErrorCode, const char* _sDescription)
{
    printf("GLFW\t\t [%d] %s\n", _nErrorCode, _sDescription);
}

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
    std::vector<float> QuadVertices = {
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f
    };

    /** Quad Indices **/
    std::vector<gx::Index> QuadIndices = {
        0u, 1u, 3u,
        1u, 2u, 3u
    };  

    /** Create VAO, VBO and EBO **/
    gx::Reference<gx::VertexArray> vertexArray = gx::VertexArray::Create();

    gx::Reference<gx::VertexBuffer> vertexBuffer = gx::VertexBuffer::Create(QuadVertices);
    vertexBuffer->SetLayout({
        gx::Attribute::Float3,
        gx::Attribute::Float2
    });
    vertexArray->AttachVertexBuffer(vertexBuffer);

    gx::Reference<gx::ElementBuffer> elementBuffer = gx::ElementBuffer::Create(QuadIndices);
    vertexArray->AttachElementBuffer(elementBuffer);

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
        gx::Reference<gx::Shader> BasicShader = gx::Shader::Create(VertS, FragS);

        /** Create Texture **/
        gx::Reference<gx::Texture2D> BasicTexture = gx::Texture2D::CreateFromFile("sandbox/resources/Image.png");

        /** Orthographic **/
        gx::Orthographic Projection = gx::Orthographic({ 800, 600 }, 10.0f);

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
                BasicTexture->Bind(0u);

                /** Bind Shader **/
                BasicShader->Bind();

                /** Set Shader Uniforms **/
                BasicShader->SetUniformMat4("uTransform", Transform);
                BasicShader->SetUniformMat4("uViewProjection", Projection);
                BasicShader->SetUniformInt("uTexture", 0);
                BasicShader->SetUniformFloat4("uTint", { 1.0f, 0.3f, 0.3f, 1.0f} );

                /** Render Quad **/
                vertexArray->Bind();
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            } /** End **/

            /** Swap GLFW Window Buffers **/
            glfwSwapBuffers(glfwWindow);
        }

    }

    DebugPrint("GLAD", "GL Objects destroyed.");

    /** Destroy the GLFW Window **/
    glfwDestroyWindow(glfwWindow);

    DebugPrint("GLFW", "Window Destroyed.");

    /** Shutdown GLFW **/
    glfwTerminate();

    return 0;
}