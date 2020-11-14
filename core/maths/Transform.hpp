/*
// Transform
*/

#ifndef _GX_MATHS_TRANSFORM_
#define _GX_MATHS_TRANSFORM_

/** Include **/
#include "Types.hpp"

_GX_BEGIN

/**
 * 
 **/
class Transform
{
private:
    bool m_RecalculationRequired;

    Vec3 m_Scale;
    Vec3 m_Position;
    Vec3 m_Rotation;

    Mat4 m_TransformationMatrix;

    void __CalculateMatrix();

public:
    Transform(const Vec3& _vPosition, const Vec3& _vScale = Vec3(1.0f), const Vec3& _vRotation = Vec3(0.0f));
    Transform();
    ~Transform();

    /*! @brief Set transform scale to _vScale
    **/
    void SetScale(const Vec3& _vScale);

    /*! @brief Set transform rotation to _vRotation
    **/
    void SetRotation(const Vec3& _vRotation);

    /*! @brief Set transform position to _vPosition
    **/
    void SetPosition(const Vec3& _vPosition);

    /*! @brief Scale the transform by _vScale
    **/
    void Scale(const Vec3& _vScale);

    /*! @brief Rotate the transform by _vRotation
    **/
    void Rotate(const Vec3& _vRotation);

    /*! @brief Translate the transform by _vTranslation
    **/
    void Translate(const Vec3& _vTranslation);

    /*! @brief Return the transfor Matrix
    **/
    Mat4 GetTransformMatrix();

    /*! @brief Call GetTransformMatrix
    **/
    inline operator Mat4()
    { return GetTransformMatrix(); }

};

_GX_END

#endif