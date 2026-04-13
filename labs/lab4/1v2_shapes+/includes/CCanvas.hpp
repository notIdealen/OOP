#pragma once


#include <SFML/Graphics.hpp>
#include "ICanvas.hpp"

class CCanvas : public ICanvas
{
public:
    explicit CCanvas(sf::RenderWindow& target) : m_window{target} {}

    void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
    void DrawPolygon(std::vector<CPoint> points, uint32_t lineColor) override;
    void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
    void DrawCircle(CPoint center, double radius, uint32_t lineColor) override;
    void FillCircle(CPoint center, double radius, uint32_t fillColor) override;
private:
    sf::RenderWindow& m_window;
};
