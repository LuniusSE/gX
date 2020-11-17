/*
// gX Namespace
*/

#ifndef _GX_NAMESPACE_
#define _GX_NAMESPACE_

#define _GX_NS                  gx

#ifndef _GX_NO_NAMESPACE_
#   define _GX_BEGIN            namespace _GX_NS {
#   define _GX_END              }
#   define _GX_USE              using namespace _GX_NS;

#   define _GX_REGION_BEGIN(N)  namespace N {
#   define _GX_REGION_END       }
#else
#   define _GX_BEGIN
#   define _GX_END
#   define _GX_USE

#   define _GX_REGION_BEGIN(N)
#   define _GX_REGION_END
#endif

#endif