#pragma once

#include <string>
#include "Shape.hpp"
#include "CPoint.hpp"

class CLineSegment : public Shape
{
public:
    CLineSegment(double startX, double startY, double endX, double endY, uint32_t outlineColor) :
    m_startPoint{startX, startY},
    m_endPoint{endX, endY},
    Shape(outlineColor)
    {}
    
    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;
    
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;

    void Draw(ICanvas& canvas) final;

    inline static std::string const type = "line";
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
};
