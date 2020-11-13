/*
// Graphics Buffers
*/

#ifndef _GX_RENDERING_BUFFERS_HEADER_
#define _GX_RENDERING_BUFFERS_HEADER_

/** Headers **/
#include <Common.hpp>
#include "Layout.hpp"
#include <vector>

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class VertexBuffer
{
public:
    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;
    static void Reset();

    virtual void SetLayout(const Layout& _aLayout) = 0;
    virtual Layout& GetLayout(void) = 0;
    virtual void SetBufferData(const void* _pData, Size _uSize) = 0;

    /*! @brief Create a new VertexBuffer Object
     *
     * @param[in] _uSize sizeof(type) * count
     * 
    **/
    static Reference<VertexBuffer> Create(Size _uSize);

    /*! @brief Create a new VertexBuffer Object
     *
     * @param[in] _pVertices raw pointer to data
     * @param[in] _uSize sizeof(type) * count
     * 
    **/
    static Reference<VertexBuffer> Create(const void* _pVertices, Size _uSize);
};

/**
 * TODO:
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