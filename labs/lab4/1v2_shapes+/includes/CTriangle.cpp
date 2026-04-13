#include <sstream>
#include <math.h>
#include <iomanip>
#include "CTriangle.hpp"


double CTriangle::GetArea() const
{
    return abs(m_vertex1.x * (m_vertex2.y - m_vertex3.y) + m_vertex2.x * (m_vertex3.y - m_vertex1.y) + m_vertex3.x * (m_vertex1.y - m_vertex2.y)) / 2;
}

double CalculateLength(CPoint v1, CPoint v2)
{
    return sqrtf((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
} 

double CTriangle::GetPerimeter() const
{
    return CalculateLength(m_vertex1, m_vertex2) + CalculateLength(m_vertex2, m_vertex3) + CalculateLength(m_vertex3, m_vertex1);
}

uint32_t CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
    return m_vertex3;
}

std::string CTriangle::ToString()
{
    std::ostringstream oss;
    oss << CTriangle::type << ":\n"
        << "  vertex1: (" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
        << "  vertex2: (" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
        << "  vertex3: (" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
        << "  outline: " << std::hex << std::setw(6) << std::setfill('0') << std::uppercase << m_outlineColor << "\n"
        << "  fill: " << std::hex << std::setw(6) << std::setfill('0') << std::uppercase << m_fillColor << "\n"
        << "  Area: " << std::fixed << std::setprecision(2) << GetArea() << "\n"
        << "  Perimeter: " << std::fixed << std::setprecision(2) << GetPerimeter() << "\n"
        << "---------------------------\n";
    return oss.str();
}

void CTriangle::Draw(ICanvas &canvas)
{
    canvas.FillPolygon({m_vertex1, m_vertex2, m_vertex3}, m_fillColor);
    canvas.DrawPolygon({m_vertex1, m_vertex2, m_vertex3}, m_outlineColor);
}
