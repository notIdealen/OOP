#pragma once

#include <string>
#include "CPoint.hpp"
#include "Shape.hpp"
#include "SolidShape.hpp"

class CRectangle : public Shape, public SolidShape
{
public:
    CRectangle(double left, double top, double width, double height, uint32_t outlineColor,  uint32_t solidColor) :
    m_x{left},
    m_y{top},
    m_width{width},
    m_height{height},
    Shape(outlineColor),
    SolidShape(solidColor)
    {}

    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;

    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;

    void Draw(ICanvas& canvas) final;
    
    inline static std::string const type = "rectangle";
private:
    double m_x;
    double m_y;
    double m_width;
    double m_height;
};
