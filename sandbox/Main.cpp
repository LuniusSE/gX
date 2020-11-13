/** gX-Sandbox **/
#include <rendering/Renderer2D.hpp>
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
        Renderer2D::Initialize();

        Orthographic Projection = Orthographic({ 800, 600 }, 10.0f);

        while (window->IsOpen())
        {
            window->Update();

            Renderer2D::BeginScene(Projection);

            Renderer2D::RenderQuad({ 1.0f, 0.3f, 0.6f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });
            Renderer2D::RenderQuad({ 1.0f, 0.3f, 0.6f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, -1.0f, -1.0f });

            Renderer2D::EndScene();

            window->GetContext()->SwapBuffers();
        }

        Renderer2D::Shutdown();
        Rendering::Shutdown();
    }

    return 0;
}