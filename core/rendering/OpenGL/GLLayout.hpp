/*
// OpenGL Layout
*/

#ifndef _GX_RENDERING_GLLAYOUT_
#define _GX_RENDERING_GLLAYOUT_

/** Headers **/
#include <Common.hpp>
#include <rendering/Layout.hpp>
#include <glad/glad.h>

_GX_REGION_BEGIN(OpenGL)

/*! @brief For use by gX OpenGL API
 * Get the type length of the given Attribute
**/
inline static gx::uInt Attribute_GetLength(const gx::Attribute& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Length **/
    case gx::Attribute::Float:  return 1;
    case gx::Attribute::Float2: return 2;
    case gx::Attribute::Float3: return 3;
    case gx::Attribute::Float4: return 4;
    default: break;
    }
    return 0u;
}

/*! @brief For use by gX OpenGL API
 * Get the type size of the given Attribute
**/
inline static gx::uInt Attribute_GetTypeSize(const gx::Attribute& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Type Size **/
    case gx::Attribute::Float:
    case gx::Attribute::Float2:
    case gx::Attribute::Float3:
    case gx::Attribute::Float4: 
        return sizeof(float);
    default: break;
    }
    return 0u;
}

/*! @brief For use by gX OpenGL API
 * Get GLenum for the given Attribute
**/
inline static gx::uInt Attribute_GetGLType(const gx::Attribute& _eAttrib)
{
    switch (_eAttrib)
    {
    /** Return Type GLenum **/
    case gx::Attribute::Float:
    case gx::Attribute::Float2:
    case gx::Attribute::Float3:
    case gx::Attribute::Float4: 
        return GL_FLOAT;
    default: break;
    }
    return 0u;
}

/*! @brief For use by gX OpenGL API
 * Automatically calculate arguments for glVertexAttribPointer
**/
inline static void HandleVertexAttribPointers(const gx::Layout& _vAttribs)
{
    /** Declare variables **/
    unsigned uStride = 0u;
    unsigned uIndex = 0u;
    int nOffset = 0u;

    /** Loop through all Attribs in _vAttribs **/
    /** Calculate Stride **/
    for(const gx::Attribute& eAttrib : _vAttribs)
    {
        uStride += Attribute_GetLength(eAttrib) * Attribute_GetTypeSize(eAttrib);
    }

    /** Loop through all Attribs in _vAttribs **/
    /** Setup VertexAttribPointers **/
    for(const gx::Attribute& eAttrib : _vAttribs)
    {
        /** Fillout VertexAttribPointer **/
        glVertexAttribPointer(uIndex, Attribute_GetLength(eAttrib), Attribute_GetGLType(eAttrib), GL_FALSE, uStride, (void*)(nOffset));
        glEnableVertexAttribArray(uIndex);

        /** Determine next offset **/
        nOffset += Attribute_GetLength(eAttrib) * Attribute_GetTypeSize(eAttrib);

        /** Increment the attrib index **/
        uIndex++;
    }
}

_GX_REGION_END

#endif