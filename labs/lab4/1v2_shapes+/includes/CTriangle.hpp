#pragma once

#include <string>
#include "CPoint.hpp"
#include "Shape.hpp"
#include "SolidShape.hpp"

class CTriangle : public Shape, public SolidShape
{
public:
    explicit CTriangle(double x1, double y1, double x2, double y2,double x3, double y3, uint32_t outlineColor,  uint32_t solidColor) :
    m_vertex1{x1, y1}, 
    m_vertex2{x2, y2},
    m_vertex3{x3, y3},
    Shape(outlineColor),
    SolidShape(solidColor)
    {}; 
    
    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() override final;

    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;

    void Draw(ICanvas& canvas) final;

    inline static std::string const type = "triangle";
private:
    CPoint m_vertex1;
    CPoint m_vertex2;
    CPoint m_vertex3;
};
