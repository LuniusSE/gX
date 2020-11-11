/*
// Graphics Arrays
*/

#ifndef _GX_RENDERING_ARRAYS_HEADER_
#define _GX_RENDERING_ARRAYS_HEADER_

/** Headers **/
#include <Common.hpp>
#include "Buffers.hpp"

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class VertexArray
{
public:
    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;
    static void Reset();

    virtual void AttachVertexBuffer(const Reference<VertexBuffer>& _pVertexBuffer) = 0;
    virtual void AttachElementBuffer(const Reference<ElementBuffer>& _pElementBuffer) = 0;

    /*! @brief Create a new VertexArray Object
    **/
    static Reference<VertexArray> Create();
};

_GX_END

#endif