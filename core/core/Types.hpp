/*
// Common Types
*/

#ifndef _GX_COMMON_TYPES_
#define _GX_COMMON_TYPES_

#include "core/Namespace.hpp"

#include <inttypes.h>

_GX_BEGIN

/** Floating Points **/
using Float     = float;

/** Redef **/
using Int       = int_least32_t;
using uInt      = uint_least32_t;
using uChar     = uint_least8_t;

/** Special Integers **/
using Index     = uInt;
using Program   = uInt;
using Size      = uInt;
using Count     = uInt;
using Time      = uInt;
using Status    =  Int;

_GX_END

#endif