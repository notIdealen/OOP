#pragma once

#include <optional>
#include <string>

class Expression
{
public:
    enum class ExpressionType: char 
    { 
        function = 'f',
        variable = 'v'
    };
    
    virtual std::optional<double> GetValue() = 0;
    // virtual std::optional<double> GetValue() const = 0;
    virtual ExpressionType GetType() = 0;

    virtual ~Expression() = default;

};
