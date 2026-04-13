#pragma once

#include <string>
#include "ISolidShape.hpp"
// #include "ICanvasDrawable.hpp"
#include "ICanvas.hpp"
#include "CPoint.hpp"

class CCircle : public ISolidShape//, public ICanvasDrawable
{
public:
    CCircle(double x, double y, double r, uint32_t shapeColor, uint32_t solidColor) : 
    m_centerPoint{x, y}, 
    m_radius{r},
    m_outlineColor{shapeColor},
    m_fillColor{solidColor}
    {}; 

    double GetArea() const final;
    double GetPerimeter() const final;
    std::string ToString() final;
    uint32_t GetOutlineColor() const final;

    uint32_t GetFillColor() const final;

    CPoint GetCenter() const;
    double GetRadius() const;

    void Draw(ICanvas& canvas) final;
    
    inline static std::string const type = "circle";
    inline static double const s_PI = 3.1415926535;
private:
    double m_radius;
    CPoint m_centerPoint;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;

    //sf::CircleShape circle; скорее всего не нунжно, этим занимается канвас
    //std::unique_ptr<ICanvasDrawable> icd;
};
