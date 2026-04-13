#pragma once

#include <string>
#include "IShape.hpp"
#include "CPoint.hpp"
// #include "ICanvasDrawable.hpp"

class CLineSegment : public IShape//, public ICanvasDrawable
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

    void Draw(ICanvas& canvas) final;

    inline static std::string const type = "line";
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
    uint32_t m_outlineColor;
};
