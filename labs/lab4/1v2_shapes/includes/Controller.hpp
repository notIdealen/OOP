#pragma once

#include <memory>
#include <vector>
#include <string>
#include "IShape.hpp"
#include "ShapeFactory.hpp"

class Controller
{
public:
    bool InsertShape(std::string& line);
    std::string GetShapeWithMinPerimeter();
    std::string GetShapeWithMaxArea();
    void PrintShapes(std::ostream& out);

private:
    std::vector<std::unique_ptr<IShape>> m_shapeStorage{};
    std::vector<std::string> m_tokens{};
    ShapeFactory m_factory;
};
