#include <sstream>
#include <iostream>

#include "Controller.hpp"

bool Controller::InsertShape(std::string& line)
{
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens{};
    
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    if (tokens.empty())
    {
        return false;
    }
    if (std::unique_ptr<IShape> shape = m_factory.CreateShape(tokens); shape)
    {
        m_shapeStorage.push_back(std::move(shape));
        return true;
    }
    return false;
}

// std::string Controller::GetShapeWithMinPerimeter()
// {
//     double minPerimeter{0};
//     size_t pos{m_shapeStorage.size()};
//     for (size_t i = 0; i < m_shapeStorage.size(); ++i)
//     {
//         auto& shape = m_shapeStorage[i];
//         if (minPerimeter > shape->GetPerimeter() || minPerimeter == 0)
//         {
//             minPerimeter = shape->GetPerimeter();
//             pos = i;
//         }
//     }
//     if (pos == m_shapeStorage.size())
//         return "Empty storage.\n";
//     std::string result = m_shapeStorage[pos]->ToString();
//     return std::move(result);
// }
IShape* Controller::GetShapeWithMinPerimeter()
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
        return nullptr;
    // std::string result = m_shapeStorage[pos]->ToString();
    // IShape* shapeMinPerimeter = m_shapeStorage[pos].get();
    return m_shapeStorage[pos].get();
}

// std::string Controller::GetShapeWithMaxArea()
// {
//     double maxSquare{0};
//     size_t pos{m_shapeStorage.size()};
//     for (size_t i = 0; i < m_shapeStorage.size(); ++i)
//     {
//         auto& shape = m_shapeStorage[i];
//         if (maxSquare < shape->GetArea())
//         {
//             maxSquare = shape->GetArea();
//             pos = i;
//         }
//     }
//     if (pos == m_shapeStorage.size())
//         return "Empty storage.\n";
//     std::string result = m_shapeStorage[pos]->ToString();
//     return std::move(result);
// }

IShape* Controller::GetShapeWithMaxArea()
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
        return nullptr;
    // std::string result = m_shapeStorage[pos]->ToString();
    return m_shapeStorage[pos].get();
}

void Controller::PrintShapes(std::ostream& out)
{
    for (const auto& shape : m_shapeStorage)
    {
        std::string info = shape->ToString();
        std::cout << info;
    }
}

void Controller::DrawAllShapes()
{
    for (const auto& shape : m_shapeStorage)
    {
        shape->Draw(m_canvas);
    }
}
