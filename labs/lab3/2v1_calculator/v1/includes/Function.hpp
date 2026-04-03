#pragma once

#include <string>
#include <memory>
#include "Expression.hpp"

class Function : public Expression
{
public:
    Function(std::shared_ptr<Expression>& left);
    Function(std::shared_ptr<Expression>& left, std::shared_ptr<Expression>& right, char operation);

    ExpressionType GetType() override;

    std::optional<double> GetValue() const override;

private:
    ExpressionType type = ExpressionType::function;
    char m_operation;
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
};
