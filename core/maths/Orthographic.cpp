/*
// Orthographic Projection
*/
#include "Orthographic.hpp"

_GX_BEGIN

/** Initialize Variables **/
Orthographic::Orthographic(const Vec2& _vSize, float _fScale)
    : m_View(IdentityMatrix), m_Projection(IdentityMatrix),
    m_Position(Vec3(0.0f, 0.0f, 1.0f)), m_Origin(Vec3(0.0f))
{
    m_Scale = _fScale;
    Resize(_vSize);

    __ResetOrthographic();
}

/** Empty **/
Orthographic::~Orthographic()
{
}

void Orthographic::__ResetOrthographic(void)
{
	float Left      = -m_Scale * m_AspectRatio * 0.5f;
	float Right     =  m_Scale * m_AspectRatio * 0.5f;
	float Bottom    = -m_Scale * 0.5f;
	float Top       =  m_Scale * 0.5f;

    float zNear     = 0.1f;
    float zFar      = 100.0f;

    m_Projection = glm::ortho(Left, Right, Bottom, Top, zNear, zFar);
    m_View = glm::lookAt(m_Position, m_Origin, Vec3(0.0f, 1.0f, 0.0f));
}

void Orthographic::Update(void)
{
    __ResetOrthographic();
}

void Orthographic::Translate(const Vec3& _vTranslation)
{
    m_Position += _vTranslation;
    TranslateOrigin(_vTranslation);
}

void Orthographic::TranslateOrigin(const Vec3& _vTranslation)
{
    m_Origin += _vTranslation;
}

void Orthographic::Resize(const Vec2& _vSize)
{
    m_AspectRatio = _vSize.x / _vSize.y;
    m_Size = _vSize;
}

void Orthographic::SetScale(float _fScale)
{
    m_Scale = _fScale;
}

void Orthographic::SetPosition(const Vec3& _vPosition)
{
    m_Position = _vPosition;
}

void Orthographic::SetOrigin(const Vec3& _vPosition)
{
    m_Origin = _vPosition;
}

Mat4 Orthographic::GetViewProjection(void)
{
    return m_Projection * m_View;
}

_GX_END