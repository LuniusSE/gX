/** gX-Sandbox **/
#include <core/Core.hpp>

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

class SandboxApp : public gx::Core {
private:
    Reference<Texture2D> m_FlagTexture;

    float m_ProjectionScale;
    Orthographic m_Projection;

    Transform m_Flag1;
    Transform m_Flag2;

    InputDevice* Keyboard;
    InputDevice* Mouse;

public:
    SandboxApp()
        : Core("gX-Sandbox"),
        Keyboard(Input::GetDevice("Keyboard")),
        Mouse(Input::GetDevice("Mouse")),
        m_ProjectionScale(10.0f),
        m_Projection(Orthographic({ 800, 600 }, m_ProjectionScale))
    {
        m_FlagTexture = Texture2D::Create("sandbox/resources/Image.png");

        m_Flag1  = Transform({ 0.0f, 5.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 0.0f });
        m_Flag2 = Transform({ 0.0f, -5.5f, 0.0f }, { 12.0f, 5.0f, 1.0f }, { 0.0f, 0.0f, 25.0f });
    }

    ~SandboxApp()
    {
    }

    bool OnWindowResized(WindowResizedEvent& _Event)
    {
        RenderCmd::GetGraphicsAPI()->SetViewport({ _Event.GetWidth(), _Event.GetHeight() });
        m_Projection.Resize({ _Event.GetWidth(), _Event.GetHeight() });

        return true;
    }

    bool OnMouseScrolled(MouseScrollEvent& _Event)
    {
        m_ProjectionScale -= _Event.GetScroll();
        m_Projection.SetScale(m_ProjectionScale);

        return true;
    }

    virtual inline void OnEvent(Event& _Event) override
    {
        EventMessanger messanger(_Event);

        messanger.Register<WindowResizedEvent>(GX_EVENT(OnWindowResized));
        messanger.Register<MouseScrollEvent>(GX_EVENT(OnMouseScrolled));
    }

    virtual inline void OnUpdate(Timestep& _ts) override
    {
        float Speed = 10.0f * _ts.GetSeconds();

        if (Keyboard->GetInputPressed(GLFW_KEY_W))
            m_Projection.Translate({ 0.0f, Speed, 0.0f });

        if (Keyboard->GetInputPressed(GLFW_KEY_A))
            m_Projection.Translate({ -Speed, 0.0f, 0.0f });

        if (Keyboard->GetInputPressed(GLFW_KEY_S))
            m_Projection.Translate({ 0.0f, -Speed, 0.0f });

        if (Keyboard->GetInputPressed(GLFW_KEY_D))
            m_Projection.Translate({ Speed, 0.0f, 0.0f });

        m_Projection.Update();

        RenderCmd::GetGraphicsAPI()->SetClearColour({ 0.025f, 0.125f, 0.225f, 1.0f });
        RenderCmd::GetGraphicsAPI()->Clear();

        Renderer2D::BeginScene(m_Projection);

        Renderer2D::RenderQuad(m_Flag1, { 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, m_FlagTexture);
        Renderer2D::RenderQuad(m_Flag2, { 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, m_FlagTexture);

        Renderer2D::EndScene();
    }

};

int main()
{
    Core* gXCore = new SandboxApp;

    while (gXCore->IsApplicationRunning())
        gXCore->OnCoreUpdate();

    delete gXCore;
    return 0;
}