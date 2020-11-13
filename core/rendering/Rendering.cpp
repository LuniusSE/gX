/*
// Graphics Rendering
*/
#include "Rendering.hpp"

_GX_BEGIN

Scope<GraphicsAPI> Rendering::s_GraphicsAPI = nullptr;

/**
 * Rendering::SetAPI Implementation
**/
void Rendering::SetAPI(const API& _eAPI)
{
    GraphicsAPI::s_API = _eAPI;
}

/**
 * Rendering::Initialize Implementation
**/
void Rendering::Initialize()
{
    s_GraphicsAPI = GraphicsAPI::Create();
}

/**
 * Rendering::Shutdown Implementation
**/
void Rendering::Shutdown(void)
{
    s_GraphicsAPI.release();
}

/**
 * Rendering::GetGraphicsAPI Implementation
**/
GraphicsAPI* Rendering::GetGraphicsAPI(void)
{
    return s_GraphicsAPI.get();
}

_GX_END