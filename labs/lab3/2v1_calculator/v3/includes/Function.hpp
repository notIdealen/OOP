#pragma once

#include <string>
#include <map>
#include <memory>
#include "Expression.hpp"

using VariablesList = std::map<std::string, std::optional<double>>;

class Function : public Expression
{
public:
    Function(std::string name, char ch, std::shared_ptr<Expression>& left);
    Function(std::string lName, char lch, std::string rName, char rch, std::shared_ptr<Expression>& left, std::shared_ptr<Expression>& right, char operation);
    ExpressionType GetType() override;
    std::optional<double> GetValue() const override;
    VariablesList& GetVariablesList() override
    {
        return variables;
    }
    std::optional<double>& GetCache() override
    {
        return cache;
    }

private:
    ExpressionType type = ExpressionType::function;
    char m_operation;
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
    VariablesList variables;
    mutable std::optional<double> cache;
};
