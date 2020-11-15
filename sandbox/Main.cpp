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
#include <io/Input.hpp>

#include <glfw/glfw3.h>

_GX_USE

Orthographic Projection = Orthographic({ 800, 600 }, 10.0f);

static void OnEvent(Event& _Event)
{
    Input::OnEvent(_Event);
}

int main()
{
    RenderCmd::SetAPI(API::OpenGL);
    Input::Initialize();
    
    Scope<Platform::Window> window = Platform::Window::Create("gX-Sandbox", 800, 600);
    window->SetEventHandler(OnEvent);

    {
        RenderCmd::Initialize();
        Renderer2D::Initialize();

        Reference<Texture2D> KazakhstaniFlag = Texture2D::Create("sandbox/resources/Image.png");

        Transform Flag  = Transform({ 0.0f, 2.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });
        Transform Flag2 = Transform({ 0.0f, -2.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });

        InputDevice& Keyboard = *Input::GetDevice("Keyboard");
        InputDevice& Mouse = *Input::GetDevice("Mouse");

        Timestep timestep;
        while (window->IsOpen())
        {
            timestep.Update(window->GetContext()->GetTime());

            {
                float Speed = 1.0f * timestep.GetSeconds();

                if (Keyboard.GetInputPressed(GLFW_KEY_W))
                    Projection.Translate({ 0.0f, Speed, 0.0f });
                
                if (Keyboard.GetInputPressed(GLFW_KEY_A))
                    Projection.Translate({ -Speed, 0.0f, 0.0f });

                if (Keyboard.GetInputPressed(GLFW_KEY_S))
                    Projection.Translate({ 0.0f, -Speed, 0.0f });

                if (Keyboard.GetInputPressed(GLFW_KEY_D))
                    Projection.Translate({ Speed, 0.0f, 0.0f });

                Projection.Update();
            }

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

    Input::Shutdown();

    return 0;
}