#pragma once

#include <string>
#include <cstdint>

class IShape
{
public:
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() = 0;
    virtual uint32_t GetOutlineColor() const = 0; 

    virtual ~IShape() = default;
protected:
    IShape() = default;
};
