#pragma once

#include <string>
#include "ICanvas.hpp"
#include "CPoint.hpp"
#include "Shape.hpp"
#include "SolidShape.hpp"

class CCircle : public Shape, public SolidShape
{
public:
    CCircle(double x, double y, double r, uint32_t shapeColor, uint32_t solidColor) : 
    m_centerPoint{x, y}, 
    m_radius{r},
    Shape{shapeColor},
    SolidShape{solidColor}
    {}; 

    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;

    CPoint GetCenter() const;
    double GetRadius() const;

    void Draw(ICanvas& canvas) final;
    
    inline static std::string const type = "circle";
    inline static double const s_PI = 3.1415926535;
private:
    double m_radius;
    CPoint m_centerPoint;
};
