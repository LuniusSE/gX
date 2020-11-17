/*
// gX Graphics Arrays API
*/

#ifndef _GX_ARRAYS_
#define _GX_ARRAYS_

#include "core/Common.hpp"
#include "rendering/Buffers.hpp"

_GX_BEGIN

/**
 * TODO:
 *  Vulkan
 **/
class VertexArray {
public:
    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;

    virtual void AttachVertexBuffer(const Reference<VertexBuffer>& _pVertexBuffer) = 0;
    virtual void AttachElementBuffer(const Reference<ElementBuffer>& _pElementBuffer) = 0;

    /*! @brief Create a new VertexArray Object
    **/
    static Reference<VertexArray> Create();
    
};

_GX_END

#endif