/*
// Graphics Buffers
*/

#ifndef _GX_RENDERING_BUFFERS_HEADER_
#define _GX_RENDERING_BUFFERS_HEADER_

/** Headers **/
#include <Common.hpp>
#include <vector>

_GX_BEGIN

/**
 * TODO:
 *  OpenGL
 *  Vulkan
 **/
class VertexBuffer
{
public:
    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;
    static void Reset();

    /*! @brief Create a new VertexBuffer Object
    **/
    static Reference<VertexBuffer> Create(const std::vector<float>& _aVertices);
};

/**
 * TODO:
 *  OpenGL
 *  Vulkan
 **/
class ElementBuffer
{
public:
    virtual ~ElementBuffer() = default;

    virtual void Bind() const = 0;
    static void Reset();

    /*! @brief Create a new ElementBuffer Object
    **/
    static Reference<ElementBuffer> Create(const std::vector<Index>& _aElements);
};

_GX_END

#endif