#include <sstream>
#include <iostream>

#include "Controller.hpp"

void Controller::InsertShape(std::string& line)
{
    std::stringstream ss(line);
    std::string token;    
    while (ss >> token)
    {
        m_tokens.push_back(token);
    }
    if (m_tokens.empty())
    {
        std::cout << "Empty input." << "\n";
        return;
    }
    if (std::unique_ptr<IShape> shape = m_factory.CreateShape(m_tokens); shape)
        m_shapeStorage.push_back(std::move(shape));
    m_tokens.clear();
}

std::string Controller::GetShapeWithMinPerimeter()
{
    double minPerimeter{0};
    size_t pos{m_shapeStorage.size()};
    for (size_t i = 0; i < m_shapeStorage.size(); ++i)
    {
        auto& shape = m_shapeStorage[i];
        if (minPerimeter > shape->GetPerimeter() || minPerimeter == 0)
        {
            minPerimeter = shape->GetPerimeter();
            pos = i;
        }
    }
    if (pos == m_shapeStorage.size())
        return "undefined, storage empty.\n";
    std::string result = m_shapeStorage[pos]->ToString();
    return std::move(result);
}

std::string Controller::GetShapeWithMaxArea()
{
    double maxSquare{0};
    size_t pos{m_shapeStorage.size()};
    for (size_t i = 0; i < m_shapeStorage.size(); ++i)
    {
        auto& shape = m_shapeStorage[i];
        if (maxSquare < shape->GetArea())
        {
            maxSquare = shape->GetArea();
            pos = i;
        }
    }
    if (pos == m_shapeStorage.size())
        return "undefined, storage empty.\n";
    std::string result = m_shapeStorage[pos]->ToString();
    return std::move(result);
}

void Controller::PrintShapes()
{
    for (const auto& shape : m_shapeStorage)
    {
        std::string info = shape->ToString();
        std::cout << info;
    }
}
