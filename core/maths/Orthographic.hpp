/*
// Orthographic Projection
*/

#ifndef _GX_ORTHOGRAPHIC_
#define _GX_ORTHOGRAPHIC_

#include "maths/Types.hpp"

_GX_BEGIN

/**
 * Orthographic Projection
 * USAGE: Camera
 **/
class Orthographic {
private:
    Mat4 m_View;
    Mat4 m_Projection;

    Vec2 m_Size;
    Vec3 m_Position;
    Vec3 m_Origin;

    float m_Scale;
    float m_AspectRatio;

    void __ResetOrthographic(void);

public:
    Orthographic(const Vec2& _vSize, float _fScale);
    ~Orthographic();

    /*! @brief Update projection math
    **/
    void Update(void);

    /*! @brief Translate the view by _vTranslation
    **/
    void Translate(const Vec3& _vTranslation);

    /*! @brief Translate the origin by _vTranslation
    **/
    void TranslateOrigin(const Vec3& _vTranslation);

    /*! @brief Resize the view to _vSize
    **/
    void Resize(const Vec2& _vSize);

    /*! @brief Set scale of the view to _fScale
    **/
    void SetScale(float _fScale);

    /*! @brief Set the position of the view to _vPosition
    **/
    void SetPosition(const Vec3& _vPosition);

    /*! @brief Set the origin of the view to _vPosition
    **/
    void SetOrigin(const Vec3& _vPosition);

    /*! @brief Return the ViewProjection matrix
    **/
    Mat4 GetViewProjection(void);

    /*! @brief Call "GetViewProjection()"
    **/
    inline operator Mat4(void)
    { return GetViewProjection(); }

    /*! @brief Call "GetViewProjection()"
    **/
    inline operator glm::mat4(void)
    { return GetViewProjection(); }

};

_GX_END

#endif