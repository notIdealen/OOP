#pragma once

#include<vector>
#include<string>
#include "ICanvas.hpp"

class MockCanvas : public ICanvas
{
public:
    explicit MockCanvas() = default;

    void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
    void DrawPolygon(std::vector<CPoint> points, uint32_t lineColor) override;
    void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
    void DrawCircle(CPoint center, double radius, uint32_t lineColor) override;
    void FillCircle(CPoint center, double radius, uint32_t fillColor) override;

    std::string m_line;
    // std::vector<std::string>& target;
    // uint32_t color;
};
