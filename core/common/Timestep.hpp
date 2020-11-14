/*
// Common Timestep
*/

#ifndef _GX_COMMON_TIMESTEP_
#define _GX_COMMON_TIMESTEP_

/** Headers **/
#include "Namespace.hpp"

_GX_BEGIN

class Timestep
{
private:
    float m_LastTime;
    float m_DeltaTime;

public:
    inline Timestep()
        : m_DeltaTime(0.0f), m_LastTime(0.0f)
    {
    }

    inline void Update(float _ThisTime)
    { 
        m_DeltaTime = _ThisTime - m_LastTime;
        m_LastTime = _ThisTime;
    }

    inline operator float() const
    {
        return m_DeltaTime;
    }

};

_GX_END

#endif