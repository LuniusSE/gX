/*
// Graphics Rendering
*/

#ifndef _GX_RENDERING_HEADER_
#define _GX_RENDERING_HEADER_

/** Headers **/
#include <Common.hpp>
#include "GraphicsAPI.hpp"

_GX_BEGIN

class Rendering
{
private:
    static Scope<GraphicsAPI> s_GraphicsAPI;

public:

    /*! @brief Create a new GraphicsAPI global instance
     * Can be either a OpenGL or Vulkan instance
    **/
    static void Initialize(const API& _eAPI);

    /*! @brief Delete the GraphicsAPI instance
    **/
    static void Shutdown(void);

    /*! @brief Get a raw pointer to the GraphicsAPI
    **/
    static GraphicsAPI* GetGraphicsAPI(void);

};

_GX_END

#endif