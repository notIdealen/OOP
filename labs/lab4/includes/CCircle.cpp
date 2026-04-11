#include <sstream>
#include "CCircle.hpp"
#include <iostream>
#include <iomanip>


double CCircle::GetArea() const
{
    return CCircle::s_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
    return 2 * CCircle::s_PI * m_radius;
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
    return m_centerPoint;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

std::string CCircle::ToString() 
{
    std::ostringstream oss;
    oss << CCircle::type << ":\n"
        << "  center: (" << m_centerPoint.x << ", " << m_centerPoint.y << ")\n"
        << "  radius: " << m_radius << "\n"
        << "  outline: " << std::hex << std::uppercase << m_outlineColor << "\n"
        << "  fill: " << std::hex << std::uppercase << m_fillColor << "\n"
        << "  Area: " << std::fixed << std::setprecision(2) << GetArea() << "\n"
        << "  Perimeter: " << std::fixed << std::setprecision(2) << GetPerimeter() << "\n"
        << "---------------------------\n";
    return oss.str();
}
