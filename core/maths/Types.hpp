/**
 * Include essential glm headers
 **/

#ifndef _GX_MATHS_
#define _GX_MATHS_

/** GLM Precision **/
#define DefaultPrecision glm::lowp

/** Headers **/
#include <common/Types.hpp>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

_GX_BEGIN

/******* Types *******/

/**     Vectors     **/

using Vec2 = glm::vec<2, Float, DefaultPrecision>;
using Vec3 = glm::vec<3, Float, DefaultPrecision>;
using Vec4 = glm::vec<4, Float, DefaultPrecision>;

/**     Matrices    **/

using Mat2 = glm::mat<2, 2, Float, DefaultPrecision>;
using Mat3 = glm::mat<3, 3, Float, DefaultPrecision>;
using Mat4 = glm::mat<4, 4, Float, DefaultPrecision>;
#define IdentityMatrix Mat4(1.0f)

/*********************/

_GX_END

#endif