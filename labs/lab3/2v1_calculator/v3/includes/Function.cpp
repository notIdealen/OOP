#include "Function.hpp"
// #include <iostream>//////////////////////////////////////////////////////////////

Function::Function(std::string name, char ch, std::shared_ptr<Expression>& left) : m_left{left}
{
    if (ch == 'v')
    {
        if (variables.find(name) == variables.end())
            variables[name] = left->GetValue();
    }
}

Function::Function(std::string lName, char lch, std::string rName, char rch, std::shared_ptr<Expression>& left, std::shared_ptr<Expression>& right, char operation) : 
m_left{left},
m_right{right},
m_operation{operation}
{
    if (lch == 'v')
    {
        if (variables.find(lName) == variables.end())
            variables[lName] = left->GetValue();
    }
    if (rch == 'v')
    {
        if (variables.find(rName) == variables.end())
        {
            variables[rName] = right->GetValue();
        }
    }
}

Expression::ExpressionType Function::GetType() 
{
    return type;
}

std::optional<double> Function::GetValue() const
{
    std::optional<double> left = m_left->GetValue();
    if (!left.has_value())
    {
        cache = left;
        return std::nullopt;
    }

    if (m_right == nullptr)
    {
        cache = left;
        return left;
    }

    std::optional<double> right = m_right->GetValue();
    if (!right.has_value())
    {
        cache = right;
        return std::nullopt;
    }

    switch (m_operation)
    {
    case '+':
        cache = left.value() + right.value();
        return cache;
    case '-':
        cache = left.value() - right.value();
        return cache;
    case '*':
        cache = left.value() * right.value();
        return cache;
    case '/':
        if (right.value() == 0.0)
        {
            cache = std::nullopt;
            return std::nullopt;
        }
        cache = left.value() / right.value();
        return cache;
    default:
        return std::nullopt;
    }
}
