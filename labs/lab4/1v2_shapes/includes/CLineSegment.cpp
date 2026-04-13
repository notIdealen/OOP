#include "CLineSegment.hpp"
#include <sstream>
#include <math.h>
#include <iomanip>

double CLineSegment::GetArea() const
{
    return 0.0;
}

double CLineSegment::GetPerimeter() const
{
    return sqrtf((m_endPoint.x - m_startPoint.x) * (m_endPoint.x - m_startPoint.x) + (m_endPoint.y - m_startPoint.y) * (m_endPoint.y - m_startPoint.y));
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

std::string CLineSegment::ToString()
{
    std::ostringstream oss;
    oss << CLineSegment::type << ":\n"
        << "  start point: (" << m_startPoint.x << ", " << m_startPoint.y << ")\n"
        << "  end point: (" << m_endPoint.x << ", " << m_endPoint.y << ")\n"
        << "  outline: " << std::hex << std::setw(6) << std::setfill('0') << std::uppercase << m_outlineColor << "\n"
        // << "  Area: " << std::fixed << std::setprecision(2) << GetArea() << "\n"
        << "  Perimeter: " << std::fixed << std::setprecision(2) << GetPerimeter() << "\n"
        << "---------------------------\n";
    return oss.str();
}
