#pragma once

#include "ISolidShape.hpp"

class SolidShape : public ISolidShape
{
public:
    SolidShape(uint32_t fillColor) :
    m_fillColor{fillColor}
    {}

    uint32_t GetFillColor() const final
    {
        return m_fillColor;
    }

protected:
    uint32_t m_fillColor;
};
