#pragma once

#include <string>
#include <vector>
#include <memory>
#include "IShape.hpp"

class ShapeFactory
{
public:
    std::unique_ptr<IShape> CreateShape(const std::vector<std::string>& args);

private:
    
};
