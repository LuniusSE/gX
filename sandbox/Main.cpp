/** gX-Sandbox **/
#include <rendering/Rendering.hpp>
#include <rendering/Arrays.hpp>
#include <rendering/Buffers.hpp>
#include <rendering/Shaders.hpp>
#include <rendering/Textures.hpp>
#include <platform/Window.hpp>
#include <maths/Orthographic.hpp>

_GX_USE

int main()
{
    Rendering::SetAPI(API::OpenGL);
    Scope<Platform::Window> window = Platform::Window::Create("gX-Sandbox", 800, 600);

    {
        Rendering::Initialize();

        const char* vertexShader = R"(
            #version 460 core

            layout (location = 0) in vec3 Position;
            layout (location = 1) in vec2 TexCoord;

            out vec2 _TexCoord;

            uniform mat4 uTransform;
            uniform mat4 uViewProjection;

            void main()
            {
                gl_Position = uViewProjection * uTransform * vec4(Position, 1.0f);
                _TexCoord = TexCoord;
            }
        )";

        const char* fragmentShader = R"(
            #version 460 core

            in vec2 _TexCoord;

            out vec4 _Colour;

            uniform sampler2D uTexture;
            uniform vec4 uTint;

            void main()
            {
                _Colour = texture(uTexture, _TexCoord) * uTint;
            }
        )";

        std::vector<float> vertices = 
        {
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };

        std::vector<Index> indices = 
        {
            0u, 1u, 3u,
            1u, 2u, 3u
        };

        Reference<VertexArray> vertexArray = VertexArray::Create();

        Reference<VertexBuffer> vertexBuffer = VertexBuffer::Create(vertices);
        vertexBuffer->SetLayout({ Attribute::Float3, Attribute::Float2 });
        vertexArray->AttachVertexBuffer(vertexBuffer);

        Reference<ElementBuffer> elementBuffer = ElementBuffer::Create(indices);
        vertexArray->AttachElementBuffer(elementBuffer);

        Reference<Shader> shader = Shader::Create(vertexShader, fragmentShader);
        Reference<Texture2D> texture = Texture2D::CreateFromFile("sandbox/resources/Image.png");

        Orthographic Projection = Orthographic({ 800, 600 }, 10.0f);
        Mat4 Transform = glm::scale(glm::mat4(1.0f), { 7.68f, 3.84f, 1.0f });

        while (window->IsOpen())
        {
            window->Update();

            {
                texture->Bind(0u);

                shader->Bind();
                shader->SetUniformInt("uTexture", 0u);
                shader->SetUniformFloat4("uTint", { 1.0f, 1.0f, 1.0f, 1.0f });
                shader->SetUniformMat4("uViewProjection", Projection);
                shader->SetUniformMat4("uTransform", Transform);

                Rendering::GetGraphicsAPI()->DrawIndexed(vertexArray, 6);
            }

            window->GetContext()->SwapBuffers();
        }

        Rendering::Shutdown();
    }

    return 0;
}