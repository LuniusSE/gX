/*
// gX RenderCommand API
*/

#include "rendering/RenderCmd.hpp"

_GX_BEGIN

Scope<GraphicsAPI> RenderCmd::s_GraphicsAPI = nullptr;

void RenderCmd::SetAPI(const API& _eAPI)
{
    GraphicsAPI::s_API = _eAPI;
}

void RenderCmd::Initialize()
{
    s_GraphicsAPI = GraphicsAPI::Create();
}

void RenderCmd::Shutdown(void)
{
    s_GraphicsAPI.release();
}

GraphicsAPI* RenderCmd::GetGraphicsAPI(void)
{
    return s_GraphicsAPI.get();
}

_GX_END