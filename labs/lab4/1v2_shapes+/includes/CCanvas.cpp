#include "CCanvas.hpp"
#include <cstdint>
#include <SFML/Graphics.hpp>

const float LINE_THICKNESS = -2.f;
const uint32_t COLOR_MASK = 0xFF;

sf::Color Uint32ToSfColor(uint32_t hex) {
    return sf::Color(
        (hex >> 16) & COLOR_MASK,
        (hex >> 8)  & COLOR_MASK,
        (hex)       & COLOR_MASK
    );
}

void CCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);
    line[0].position = sf::Vector2f(from.x, from.y);
    line[1].position = sf::Vector2f(to.x, to.y);
    line[0].color = Uint32ToSfColor(lineColor);
    line[1].color = Uint32ToSfColor(lineColor);
    m_window.draw(line);
}

void CCanvas::DrawPolygon(std::vector<CPoint> points, uint32_t lineColor)
{
    sf::ConvexShape shape;
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(Uint32ToSfColor(lineColor));
    shape.setOutlineThickness(LINE_THICKNESS);
    shape.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); ++i)
        shape.setPoint(i, {static_cast<float>(points[i].x), static_cast<float>(points[i].y)});
    m_window.draw(shape);
}

void CCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
    sf::ConvexShape shape;
    shape.setFillColor(Uint32ToSfColor(fillColor));
    shape.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); ++i)
        shape.setPoint(i, {static_cast<float>(points[i].x), static_cast<float>(points[i].y)});
    m_window.draw(shape);
}

void CCanvas::DrawCircle(CPoint center, double radius, uint32_t lineColor)
{
    sf::CircleShape circle;
    circle.setRadius(static_cast<float>(radius));
    circle.setPosition({static_cast<float>(center.x - radius), static_cast<float>(center.y - radius)});
    circle.setOutlineColor(Uint32ToSfColor(lineColor));
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(LINE_THICKNESS);
    m_window.draw(circle);
}

void CCanvas::FillCircle(CPoint center, double radius, uint32_t fillColor)
{
    sf::CircleShape circle;
    circle.setRadius(static_cast<float>(radius));
    circle.setPosition({static_cast<float>(center.x - radius), static_cast<float>(center.y - radius)});
    circle.setFillColor(Uint32ToSfColor(fillColor));
    m_window.draw(circle);
}
