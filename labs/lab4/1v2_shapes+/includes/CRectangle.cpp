#include <sstream>
#include <iomanip>
#include "CRectangle.hpp"

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return (m_width + m_height) * 2;
}

CPoint CRectangle::GetLeftTop() const
{
    return CPoint{m_x, m_y};
}

CPoint CRectangle::GetRightBottom() const
{
    return CPoint{m_x + m_width, m_y + m_height};
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}

std::string CRectangle::ToString()
{
    std::ostringstream oss;
    oss << CRectangle::type << ":\n"
        << "  Top-left vertex: (" << m_x << ", " << m_y << ")\n"
        << "  width: " << m_width << "\n"
        << "  height: " << m_height << "\n"
        << "  outline: " << std::hex << std::setw(6) << std::setfill('0') << std::uppercase << m_outlineColor << "\n"
        << "  fill: " << std::hex << std::setw(6) << std::setfill('0') << std::uppercase << m_fillColor << "\n"
        << "  Area: " << std::fixed << std::setprecision(2) << GetArea() << "\n"
        << "  Perimeter: " << std::fixed << std::setprecision(2) << GetPerimeter() << "\n"
        << "---------------------------\n";
    return oss.str();
}

void CRectangle::Draw(ICanvas& canvas)
{
    canvas.FillPolygon({{m_x, m_y},{m_x + m_width, m_y},{m_x + m_width, m_y + m_height},{m_x, m_y + m_height}}, m_fillColor);
    canvas.DrawPolygon({{m_x, m_y},{m_x + m_width, m_y},{m_x + m_width, m_y + m_height},{m_x, m_y + m_height}}, m_outlineColor);
}
