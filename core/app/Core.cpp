/*
// Common App
*/
#include "Core.hpp"

#include <io/Input.hpp>
#include <rendering/RenderCmd.hpp>
#include <rendering/Renderer2D.hpp>

_GX_BEGIN

Core::Core(const std::string& _ApplicationTitle)
    : m_Title(_ApplicationTitle), m_Running(true)
{
    InitializePlatform();
    InitializeCore();
}

Core::~Core()
{
    ShutdownPlatform();
    ShutdownCore();
}

void Core::InitializePlatform(void)
{
    m_Window = Platform::Window::Create(m_Title, 800, 600);
    m_Window->SetEventHandler(GX_EVENT(OnCoreEvent));
}

void Core::ShutdownPlatform(void)
{
}

void Core::InitializeCore(void)
{
    Input::Initialize();

    RenderCmd::SetAPI(API::OpenGL);
    RenderCmd::Initialize();

    Renderer2D::Initialize();
}

void Core::ShutdownCore(void)
{
    RenderCmd::Shutdown();
    Renderer2D::Shutdown();

    Input::Shutdown();
}

void Core::OnCoreUpdate(void)
{
    m_Timestep.Update(m_Window->GetContext()->GetTime());
    m_Window->Update();
    
    OnUpdate(m_Timestep);
    m_Window->GetContext()->SwapBuffers();
}

bool Core::OnWindowClosedEvent(WindowClosedEvent& _Event)
{
    m_Running = false;
    return true;
}

void Core::OnCoreEvent(Event& _Event)
{
    Input::OnEvent(_Event);

    EventMessanger messanger(_Event);
    messanger.Register<WindowClosedEvent>(GX_EVENT(OnWindowClosedEvent));

    OnEvent(_Event);
}

_GX_END