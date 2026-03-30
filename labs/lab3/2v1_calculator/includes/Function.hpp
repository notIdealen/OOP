#pragma once

#include <string>
#include <limits>
#include <optional>
#include "Expression.hpp"

// use sharedptr insteed ptr
class Function : public Expression
{
public:
    Function(Expression &left, Expression &right, std::string_view operation) : m_left{&left},
                                                                                m_right{&right}
    {
        if (operation.size() == 1)
            for (const char op : validOperations)
                if (operation[0] == op)
                {
                    m_operation = op;
                    return;
                }
        m_operation = 'x';
    }

    const std::string& GetType() override
    {
        return type;
    }

    std::optional<double> GetValue() const override
    {
        if (!m_left->GetValue().has_value())
            return std::nullopt;    
        double left = m_left->GetValue().value();

        if (m_right == nullptr)
            return left;

        if (!m_right->GetValue().has_value())
            return std::nullopt;   
        double right = m_right->GetValue().value();

        switch (m_operation)
        {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right == 0.0)
                return std::nullopt;
            return left / right;
        }
    }

private:
    inline static const std::string type = "function";
    char m_operation;
    Expression *m_left;
    Expression *m_right;
    std::string m_cache = "nan";
    inline static const char validOperations[4] = {'+', '-', '*', '/'};
};
