/*
// Core LayerStack
*/

#ifndef _GX_LAYERSTACK_
#define _GX_LAYERSTACK_

#include "Layer.hpp"

#include <vector>

_GX_BEGIN

class LayerStack {
private:
    std::vector<Layer*> m_Layers;
    Index m_LayerIndex;

public:
    LayerStack();
    ~LayerStack();

    void Push(Layer* _pLayer);
    void PushOverlay(Layer* _pOverlayLayer);

    void Pop(Layer* _pLayer);
    void PopOverlay(Layer* _pOverlayLayer);

    /** Iterators **/
    inline std::vector<Layer*>::iterator begin()
    { return m_Layers.begin(); }
    inline std::vector<Layer*>::iterator end()
    { return m_Layers.end(); }

    inline std::vector<Layer*>::reverse_iterator rbegin()
    { return m_Layers.rbegin(); }
    inline std::vector<Layer*>::reverse_iterator rend()
    { return m_Layers.rend(); }

    /** const Iterators **/
    inline std::vector<Layer*>::const_iterator begin() const 
    { return m_Layers.begin(); }
    inline std::vector<Layer*>::const_iterator end() const
    { return m_Layers.end(); }

    inline std::vector<Layer*>::const_reverse_iterator rbegin() const
    { return m_Layers.rbegin(); }
    inline std::vector<Layer*>::const_reverse_iterator rend() const
    { return m_Layers.rend(); }

};

_GX_END

#endif