#pragma once

#include <string>
#include "ISolidShape.hpp"
#include "CPoint.hpp"

class CCircle : public ISolidShape
{
public:
    CCircle(double x, double y, double r, uint32_t shapeColor, uint32_t solidColor) : 
    m_centerPoint{x, y}, 
    m_radius{r},
    m_outlineColor{shapeColor},
    m_fillColor{solidColor}
    {}; 

    double GetArea() const final;
    double GetPerimeter() const override;
    std::string ToString() final;
    uint32_t GetOutlineColor() const final;

    uint32_t GetFillColor() const final;

    CPoint GetCenter() const;
    double GetRadius() const;

private:
    double m_radius;
    CPoint m_centerPoint;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
    
    inline static std::string const type = "circle";
    inline static double const s_PI = 3.1415926535;
};
