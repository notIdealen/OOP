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

uint32_t CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
    return CPoint{m_left, m_top};
}

CPoint CRectangle::GetRightBottom() const
{
    return CPoint{m_left + m_width, m_top + m_height};
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
        << "  Top-left vertex: (" << m_left << ", " << m_top << ")\n"
        << "  width: " << m_width << "\n"
        << "  height: " << m_height << "\n"
        << "  outline: " << std::hex << std::uppercase << m_outlineColor << "\n"
        << "  fill: " << std::hex << std::uppercase << m_fillColor << "\n"
        << "  Area: " << std::fixed << std::setprecision(2) << GetArea() << "\n"
        << "  Perimeter: " << std::fixed << std::setprecision(2) << GetPerimeter() << "\n"
        << "---------------------------\n";
    return oss.str();
}
