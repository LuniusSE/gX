/*
// Core App
*/

#ifndef _GX_CORE_
#define _GX_CORE_

#include "core/LayerStack.hpp"
#include "core/Timestep.hpp"
#include "io/Events.hpp"
#include "platform/Window.hpp"

#include <string>

_GX_BEGIN

class Core {
private:
    bool OnWindowClosedEvent(WindowClosedEvent& _Event);

protected:
    std::string m_Title;
    Scope<Platform::Window> m_Window;
    LayerStack m_Stack;
    Timestep m_Timestep;
    bool m_Running;

public:
    Core(const std::string& _ApplicationTitle);
    ~Core();

    inline bool IsApplicationRunning() const
    { return m_Running; }

    inline void CloseApplication()
    { m_Running = false; }

    inline void PushLayer(Layer* _pLayer)
    { m_Stack.Push(_pLayer); }

    void InitializePlatform(void);
    void ShutdownPlatform(void);

    void InitializeCore(void);
    void ShutdownCore(void);

    void OnCoreUpdate(void);
    void OnCoreEvent(Event& _Event);

    virtual void OnUpdate(Timestep& _Timestep) = 0;
    virtual void OnEvent(Event& _Event) = 0;
    
};

_GX_END

#endif