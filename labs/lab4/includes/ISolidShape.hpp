#pragma once

#include <cstdint>
#include "IShape.hpp"

class ISolidShape : public IShape
{
public:
    virtual uint32_t GetFillColor() const = 0;
    
    virtual ~ISolidShape() = default;

protected:
    ISolidShape() = default;
    
};

