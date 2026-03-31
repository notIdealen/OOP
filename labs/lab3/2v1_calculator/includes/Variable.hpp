#pragma once

#include "Expression.hpp"
#include <string>

class Variable : public Expression
{
public:
    Variable(std::optional<double> num);

    void SetValue(std::optional<double> num);

    std::optional<double> GetValue() const;

    ExpressionType GetType();
    
private:
    ExpressionType type = ExpressionType::variable;
    std::optional<double> m_value;
};
