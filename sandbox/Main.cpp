/** gX-Sandbox **/
#include <rendering/Renderer2D.hpp>
#include <rendering/RenderCmd.hpp>
#include <rendering/Arrays.hpp>
#include <rendering/Buffers.hpp>
#include <rendering/Shaders.hpp>
#include <rendering/Textures.hpp>
#include <platform/Window.hpp>
#include <maths/Orthographic.hpp>
#include <maths/Transform.hpp>

_GX_USE

int main()
{
    RenderCmd::SetAPI(API::OpenGL);
    Scope<Platform::Window> window = Platform::Window::Create("gX-Sandbox", 800, 600);

    {
        RenderCmd::Initialize();
        Renderer2D::Initialize();

        Orthographic Projection = Orthographic({ 800, 600 }, 10.0f);
        Reference<Texture2D> KazakhstaniFlag = Texture2D::Create("sandbox/resources/Image.png");

        Transform Flag  = Transform({ 0.0f, 2.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });
        Transform Flag2 = Transform({ 0.0f, -2.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });

        Timestep timestep;
        while (window->IsOpen())
        {
            timestep.Update(window->GetContext()->GetTime());

            window->Update();

            RenderCmd::GetGraphicsAPI()->SetClearColour({ 0.025f, 0.025f, 0.025f, 1.0f });
            RenderCmd::GetGraphicsAPI()->Clear();
            
            Renderer2D::BeginScene(Projection);

            Renderer2D::RenderQuad(Flag, { 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, KazakhstaniFlag);
            Renderer2D::RenderQuad(Flag2, { 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, KazakhstaniFlag);

            Renderer2D::EndScene();

            window->GetContext()->SwapBuffers();
        }

        Renderer2D::Shutdown();
        RenderCmd::Shutdown();
    }

    return 0;
}