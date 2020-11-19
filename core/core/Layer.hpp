/*
// Core Layer
*/

#ifndef _GX_LAYER_
#define _GX_LAYER_

#include <string>

#include "core/Types.hpp"
#include "core/Timestep.hpp"
#include "io/Events.hpp"

_GX_BEGIN

class Layer {
protected:
    std::string m_LayerName;

public:
    inline Layer(const std::string& _Name) : m_LayerName(_Name) {}
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