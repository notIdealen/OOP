#include "Function.hpp"
#include <iostream>/////////////

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

std::optional<double> Function::GetValue()// const
{
    // if (m_resultCache.has_value())
    //     return m_resultCache;
    std::optional<double> left = m_left->GetValue();

    if (!left.has_value())
    {
        m_leftCache = std::nullopt;
        m_rightCache = std::nullopt;
        m_resultCache = std::nullopt;
        return std::nullopt;
    }

    if (m_right == nullptr && m_leftCache == left)
    {
        m_resultCache = m_leftCache;
        return m_resultCache;
    }
    if (m_right == nullptr && m_leftCache != left)
    {
        m_leftCache = left;
        m_resultCache = m_leftCache;
        return m_resultCache;
    }
    
    std::optional<double> right = m_right->GetValue();
    if (!right.has_value())
    {
        m_leftCache = std::nullopt;
        m_rightCache = std::nullopt;
        m_resultCache = std::nullopt;
        return std::nullopt;
    }

    if (m_leftCache == left && m_rightCache == right)
    {
        return m_resultCache;
    }

    m_leftCache = left;
    m_rightCache = right;

    switch (m_operation)
    {
    case '+':
        m_resultCache = left.value() + right.value();
        return m_resultCache;
    case '-':
        m_resultCache = left.value() - right.value();
        return m_resultCache;
    case '*':
        m_resultCache =  left.value() * right.value();
        return m_resultCache;
    case '/':
        if (right.value() == 0.0)
            return std::nullopt;
        m_resultCache = left.value() / right.value();
        return m_resultCache;
    default:
        return std::nullopt;
    }
}
