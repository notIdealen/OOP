#pragma once

#include <memory>
// #include <vector>
#include <string>
// #include "IShape.hpp"
#include "ShapeFactory.hpp"

class Controller
{
public:
    void InsertShape(std::string& line);
    std::string GetShapeWithMinPerimeter();
    std::string GetShapeWithMaxArea();
    void PrintShapes();

private:
    std::vector<std::unique_ptr<IShape>> m_shapeStorage{};
    std::vector<std::string> m_tokens{};
    ShapeFactory m_factory;
};
