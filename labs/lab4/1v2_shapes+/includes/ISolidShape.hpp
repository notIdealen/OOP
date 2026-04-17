#pragma once

#include <cstdint>
#include "IShape.hpp"

// class ISolidShape : public IShape
class ISolidShape
{
public:
    virtual uint32_t GetFillColor() const = 0;
    
    virtual ~ISolidShape() = default;
};

