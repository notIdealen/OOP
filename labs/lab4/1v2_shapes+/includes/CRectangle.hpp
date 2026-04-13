#pragma once

#include <string>
#include "ISolidShape.hpp"
#include "CPoint.hpp"
// #include "ICanvasDrawable.hpp"

class CRectangle : public ISolidShape//, public ICanvasDrawable
{
public:
    CRectangle(double left, double top, double width, double height, uint32_t shapeColor,  uint32_t solidColor) :
    m_x{left},
    m_y{top},
    m_width{width},
    m_height{height},
    m_outlineColor{shapeColor},
    m_fillColor{solidColor}
    {}

    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;
    uint32_t GetOutlineColor() const final;
    
    uint32_t GetFillColor() const final;

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
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
};
