/*
// gX Namespace
*/

#ifndef _GX_COMMON_NAMESPACE_
#define _GX_COMMON_NAMESPACE_

#ifndef _GX_NO_NAMESPACE_
#   define _GX_BEGIN           namespace _GX_NS {
#   define _GX_END             }
#   define _GX_USE             using namespace _GX_NS;

#   define _GX_INCLUDE_BEGIN   namespace _GX_INC_NAME {
#   define _GX_INCLUDE_END     }
#else
#   define _GX_BEGIN
#   define _GX_END
#   define _GX_USE

#   define _GX_INCLUDE_BEGIN
#   define _GX_INCLUDE_END
#endif

#endif