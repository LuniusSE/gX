/*
// Graphics API
*/
#include "GraphicsAPI.hpp"

/** Headers **/
#include "OpenGL/GLApi.hpp"

_GX_BEGIN

/** Set the Default API to None **/
API GraphicsAPI::s_API = API::None;

/**
 * GraphicsAPI::Create Implementation
**/
Scope<GraphicsAPI> GraphicsAPI::Create()
{
    return CreateScope<OpenGL::GraphicsAPI>();
}

_GX_END