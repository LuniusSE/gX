/*
// Graphics Render Command
*/
#include "RenderCmd.hpp"

_GX_BEGIN

Scope<GraphicsAPI> RenderCmd::s_GraphicsAPI = nullptr;

/**
 * RenderCmd::SetAPI Implementation
**/
void RenderCmd::SetAPI(const API& _eAPI)
{
    GraphicsAPI::s_API = _eAPI;
}

/**
 * RenderCmd::Initialize Implementation
**/
void RenderCmd::Initialize()
{
    s_GraphicsAPI = GraphicsAPI::Create();
}

/**
 * RenderCmd::Shutdown Implementation
**/
void RenderCmd::Shutdown(void)
{
    s_GraphicsAPI.release();
}

/**
 * RenderCmd::GetGraphicsAPI Implementation
**/
GraphicsAPI* RenderCmd::GetGraphicsAPI(void)
{
    return s_GraphicsAPI.get();
}

_GX_END