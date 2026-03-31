#include "Function.hpp"

Function::Function(std::shared_ptr<Expression>& left) : m_left{left}
{}

Function::Function(std::shared_ptr<Expression>& left, std::shared_ptr<Expression>& right, char operation) : 
m_left{left},
m_right{right},
m_operation{operation}
{}

Expression::ExpressionType Function::GetType() 
{
    return type;
}

std::optional<double> Function::GetValue() const
{
    std::optional<double> left = m_left->GetValue();
    if (!left.has_value())
        return std::nullopt;

    if (m_right == nullptr)
        return left;

    std::optional<double> right = m_right->GetValue();
    if (!left.has_value())
        return std::nullopt;

    switch (m_operation)
    {
    case '+':
        return left.value() + right.value();
    case '-':
        return left.value() - right.value();
    case '*':
        return left.value() * right.value();
    case '/':
        if (right.value() == 0.0)
            return std::nullopt;
        return left.value() / right.value();
    default:
        return std::nullopt;
    }
}
