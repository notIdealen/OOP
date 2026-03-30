#pragma once

#include <map>
#include <optional>

class Expression
{
public:
    virtual std::optional<double> GetValue() const = 0;
    virtual ~Expression() = default;
    virtual const std::string& GetType() = 0;
};


