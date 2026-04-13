#include "MockCanvas.hpp"
#include <sstream>
#include <iomanip>

void MockCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
    std::ostringstream oss;
    oss << from.x << ' ' << from.y << ' ' << to.x << ' ' << to.y << ' ' << std::hex << std::setw(6) << std::setfill('0') << lineColor;
    m_line = oss.str();
}

void MockCanvas::DrawPolygon(std::vector<CPoint> points, uint32_t lineColor)
{
    std::ostringstream oss;
    for (const auto& point : points)
        oss << point.x << ' ' << point.y << ' ';
    oss << std::hex << std::setw(6) << std::setfill('0') << lineColor;
    m_line = oss.str();
}

void MockCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
    std::ostringstream oss;
    for (const auto& point : points)
        oss << point.x << ' ' << point.y << ' ';
    oss << std::hex << std::setw(6) << std::setfill('0') << fillColor;
    m_line = oss.str();
}

void MockCanvas::DrawCircle(CPoint center, double radius, uint32_t lineColor)
{
    std::ostringstream oss;
    oss << center.x << ' ' << center.y << ' ' << radius << ' ' << std::hex << std::setw(6) << std::setfill('0') << lineColor;
    m_line = oss.str();
}

void MockCanvas::FillCircle(CPoint center, double radius, uint32_t fillColor)
{
    std::ostringstream oss;
    oss << center.x << ' ' << center.y << ' ' << radius << ' ' 
        << std::hex << std::setw(6) << std::setfill('0') << fillColor;
    m_line = oss.str();
}
