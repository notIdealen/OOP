#pragma once

#include <memory>
#include <vector>
#include <string>
#include "IShape.hpp"
#include "ShapeFactory.hpp"
#include "CCanvas.hpp"

class Controller
{
public:
    Controller(sf::RenderWindow& window) :
    m_canvas(window)
    {};
    bool InsertShape(std::string& line);
    IShape* GetShapeWithMinPerimeter();
    // std::string GetShapeWithMinPerimeter();
    IShape* GetShapeWithMaxArea();
    // std::string GetShapeWithMaxArea();
    void PrintShapes(std::ostream& out);

    void DrawAllShapes();

private:
    std::vector<std::unique_ptr<IShape>> m_shapeStorage{};
    ShapeFactory m_factory;
    CCanvas m_canvas; 
};
