/*
// gX RenderCommand API
*/

#ifndef _GX_RENDERCMD_
#define _GX_RENDERCMD_

#include "core/Common.hpp"
#include "rendering/GraphicsAPI.hpp"

_GX_BEGIN

class RenderCmd {
private:
    static Scope<GraphicsAPI> s_GraphicsAPI;

public:
    /*! @brief Create a new GraphicsAPI global instance
     * Can be either a OpenGL or Vulkan instance
    **/
    static void SetAPI(const API& _eAPI);

    /*! @brief Create a new GraphicsAPI global instance
     * Can be either a OpenGL or Vulkan instance
    **/
    static void Initialize();

    /*! @brief Delete the GraphicsAPI instance
    **/
    static void Shutdown(void);

    /*! @brief Get a raw pointer to the GraphicsAPI
    **/
    static GraphicsAPI* GetGraphicsAPI(void);

};

_GX_END

#endif