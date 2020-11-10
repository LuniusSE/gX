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

/** Redef **/
using Int       = int_least32_t;
using uInt      = uint_least32_t;

/** Special Integers **/
using Index     = uInt;
using Program   = uInt;
using Size      = uInt;
using Count     = uInt;
using Time      = uInt;
using Status    =  Int;

_GX_END

#endif