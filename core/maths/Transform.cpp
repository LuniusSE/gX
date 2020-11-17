/*
// Orthographic Projection
*/

#include "maths/Transform.hpp"

_GX_BEGIN

Transform::Transform(const Vec3& _vPosition, const Vec3& _vScale, const Vec3& _vRotation)
    : m_RecalculationRequired(true), m_Position(_vPosition), m_Scale(_vScale), m_Rotation(_vRotation)
{
    __CalculateMatrix();
}

Transform::Transform()
    : m_RecalculationRequired(true), m_Position(0.0f), m_Scale(1.0f), m_Rotation(0.0f)
{
    __CalculateMatrix();
}

/** Empty **/
Transform::~Transform()
{
}

void Transform::__CalculateMatrix()
{
    if (!m_RecalculationRequired)
        return;
    
    m_TransformationMatrix = Mat4(1.0f);

    m_TransformationMatrix *= glm::translate(Mat4(1.0f), m_Position);

    m_TransformationMatrix *= glm::rotate(Mat4(1.0f), m_Rotation.x, Vec3(1.0f, 0.0f, 0.0f));
    m_TransformationMatrix *= glm::rotate(Mat4(1.0f), m_Rotation.y, Vec3(0.0f, 1.0f, 0.0f));
    m_TransformationMatrix *= glm::rotate(Mat4(1.0f), m_Rotation.z, Vec3(0.0f, 0.0f, 1.0f));

    m_TransformationMatrix *= glm::scale(Mat4(1.0f), m_Scale);
    
    m_RecalculationRequired = false;
}

void Transform::SetScale(const Vec3& _vScale)
{
    m_Scale = _vScale;
    m_RecalculationRequired = true;
}

void Transform::SetRotation(const Vec3& _vRotation)
{
    m_Rotation = _vRotation;
    m_RecalculationRequired = true;
}

void Transform::SetPosition(const Vec3& _vPosition)
{
    m_Position = _vPosition;
    m_RecalculationRequired = true;
}

void Transform::Scale(const Vec3& _vScale)
{
    m_Scale += _vScale;
    m_RecalculationRequired = true;
}

void Transform::Rotate(const Vec3& _vRotation)
{
    m_Rotation += _vRotation;
    m_RecalculationRequired = true;
}

void Transform::Translate(const Vec3& _vTranslation)
{
    m_Position += _vTranslation;
    m_RecalculationRequired = true;
}

Mat4 Transform::GetTransformMatrix()
{
    __CalculateMatrix();
    return m_TransformationMatrix;
}

_GX_END