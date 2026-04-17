#pragma once

#include "IShape.hpp"

class Shape : public IShape
{
public:
    Shape(uint32_t outlineColor) :
    m_outlineColor{outlineColor}
    {}

    uint32_t GetOutlineColor() const final
    {
        return m_outlineColor;
    } 
    
protected:
    uint32_t m_outlineColor;
};
