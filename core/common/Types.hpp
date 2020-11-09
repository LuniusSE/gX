/*
// Common Types
*/

#ifndef _GX_COMMON_TYPES_
#define _GX_COMMON_TYPES_

/** Headers **/
#include <inttypes.h>
#include "Namespace.hpp"

_GX_BEGIN

/** Floating Points **/
using Float     = float;

/** Special Integers **/
using Index     = uint_least32_t;
using Program   = uint_least32_t;
using Size      = uint_least32_t;
using Time      = uint_least32_t;
using Status    =  int_least32_t;

_GX_END

#endif