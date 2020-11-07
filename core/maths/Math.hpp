/**
 * Include essential glm headers
 **/

/** core/maths/Math.hpp Gaurd Block **/
#ifndef _GX_MATHS_HEADER_
#define _GX_MATHS_HEADER_

/** GLM Precision **/
#define DefaultPrecision glm::lowp

/** Headers **/
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

/******* Types *******/

/**     Vectors     **/
using Vec2 = glm::vec<2, float, DefaultPrecision>;
using Vec3 = glm::vec<3, float, DefaultPrecision>;
using Vec4 = glm::vec<4, float, DefaultPrecision>;

/**     Matrices    **/
using Mat2 = glm::mat<2, 2, float, DefaultPrecision>;
using Mat3 = glm::mat<3, 3, float, DefaultPrecision>;
using Mat4 = glm::mat<4, 4, float, DefaultPrecision>;
#define IdentityMatrix Mat4(1.0f)

/*********************/

#endif