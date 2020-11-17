/*
// gX Graphics API
*/

#include "rendering/GraphicsAPI.hpp"
#include "rendering/OpenGL/GLApi.hpp"

_GX_BEGIN

/** Set the Default API to None **/
API GraphicsAPI::s_API = API::None;

Scope<GraphicsAPI> GraphicsAPI::Create()
{
    return CreateScope<OpenGL::GraphicsAPI>();
}

_GX_END