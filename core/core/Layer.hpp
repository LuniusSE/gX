/*
// Core Layer
*/

#ifndef _GX_CORE_LAYER_
#define _GX_CORE_LAYER_

/** Headers **/
#include "Timestep.hpp"
#include <io/Events.hpp>
#include <string>

_GX_BEGIN

class Layer
{
protected:
    class LayerStack* m_ParentStack;
    Index m_StackPosition;

    std::string m_LayerName;

public:
    inline Layer(const std::string& _Name)
        : m_LayerName(_Name), m_ParentStack(nullptr), m_StackPosition(0u) {}
    virtual ~Layer() = default;

    inline const char* GetName() const 
    { return m_LayerName.c_str(); }

    virtual void OnAttach() = 0;
    virtual void OnDetach() = 0;
    
    virtual void OnUpdate(Timestep& _Timestep) = 0;
    virtual void OnEvent(Event& _Event) = 0;

};

_GX_END

#endif