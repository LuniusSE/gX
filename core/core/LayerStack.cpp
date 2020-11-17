/*
// Core LayerStack
*/
#include "LayerStack.hpp"

_GX_BEGIN

LayerStack::LayerStack()
    : m_LayerIndex(0u)
{
}

LayerStack::~LayerStack()
{
    for (Layer* pLayer : m_Layers)
    {
        pLayer->OnDetach();

        /** TODO: Use Custom Allocator **/
        delete pLayer;
    }
}

void LayerStack::Push(Layer* _pLayer)
{
    m_Layers.emplace(m_Layers.begin() + m_LayerIndex, _pLayer);

    m_LayerIndex++;
}

void LayerStack::Pop(Layer* _pLayer)
{
    auto iterator = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerIndex, _pLayer);
    if (iterator != m_Layers.begin() + m_LayerIndex)
    {
        _pLayer->OnDetach();

        m_LayerIndex--;
        m_Layers.erase(iterator);
    }
}

void LayerStack::PushOverlay(Layer* _pOverlayLayer)
{
    m_Layers.emplace_back(_pOverlayLayer);
}

void LayerStack::PopOverlay(Layer* _pOverlayLayer)
{
    auto iterator = std::find(m_Layers.begin() + m_LayerIndex, m_Layers.end(), _pOverlayLayer);

    if (iterator != m_Layers.end())
    {
        _pOverlayLayer->OnDetach();

        m_Layers.erase(iterator);
    }
}

_GX_END