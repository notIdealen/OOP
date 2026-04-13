#pragma once

#include <string>
#include "IShape.hpp"
#include "CPoint.hpp"

class CLineSegment : public IShape
{
public:
    CLineSegment(double startX, double startY, double endX, double endY, uint32_t shapeColor) :
    m_startPoint{startX, startY},
    m_endPoint{endX, endY},
    m_outlineColor{shapeColor}
    {}
    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;
    uint32_t GetOutlineColor() const final;
    
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;

    inline static std::string const type = "line";
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
    uint32_t m_outlineColor;
};
