/*
// gX Shader Layout API
*/

#ifndef _GX_LAYOUT_
#define _GX_LAYOUT_

#include "core/Common.hpp"

#include <vector>

_GX_BEGIN

/*! @brief Layout of VertexBuffers for Shaders.
 * Implementation of Layouts vary between APIs (e.g. OpenGL, Vulkan)
 */
typedef enum class LayoutAttributes {
    Int,

    Float,
    Float2,
    Float3,
    Float4,

    Mat2,
    Mat3,
    Mat4
}Attribute;

/*! @brief Shader Layout type
 **/
using Layout = std::vector<Attribute>;

_GX_END

#endif