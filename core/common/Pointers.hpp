/*
// Pointers
*/

#ifndef _GX_COMMON_POINTERS_
#define _GX_COMMON_POINTERS_

/** Headers **/
#include "Common.hpp"
#include <memory>

_GX_BEGIN

/**
 * Raw Pointer
 *  Void Pointer
 **/
using RawPtr = void*;

/**
 * Redefinition of std type std::shared_ptr
 **/
template<typename T>
using Reference = std::shared_ptr<T>;

/*! @brief Wrapper of std::make_shared for Reference type
 **/
template<typename T, typename ...A>
static inline constexpr Reference<T> CreateRef(A&&... _tAll)
{
    return std::make_shared<T>(std::forward<A>(_tAll)...);
}

/*! @brief Redefinition of std type std::unique_ptr
 **/
template<typename T>
using Scope = std::unique_ptr<T>;

/*! @brief Wrapper of std::make_unique for Scope type
 **/
template<typename T, typename ...A>
static inline constexpr Scope<T> CreateScope(A&&... _tAll)
{
    return std::make_unique<T>(std::forward<A>(_tAll)...);
}

_GX_END

#endif