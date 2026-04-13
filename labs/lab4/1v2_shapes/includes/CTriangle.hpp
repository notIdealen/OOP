#pragma once

#include <string>
#include "ISolidShape.hpp"
#include "CPoint.hpp"

class CTriangle : public ISolidShape
{
public:
    explicit CTriangle(double x1, double y1, double x2, double y2,double x3, double y3, uint32_t shapeColor,  uint32_t solidColor) : 
    m_vertex1{x1, y1}, 
    m_vertex2{x2, y2},
    m_vertex3{x3, y3},
    m_outlineColor{shapeColor},
    m_fillColor{solidColor}
    {}; 
    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() override final;
    uint32_t GetOutlineColor() const final;
    
    uint32_t GetFillColor() const final;

    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;

    inline static std::string const type = "triangle";
private:
    CPoint m_vertex1;
    CPoint m_vertex2;
    CPoint m_vertex3;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
};
