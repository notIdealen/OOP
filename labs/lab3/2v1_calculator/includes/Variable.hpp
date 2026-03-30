#pragma once

#include "Expression.hpp"
#include <string>
#include <optional>

class Variable : public Expression
{
public:
    Variable() = default;
    Variable(std::optional<double> num) : m_value{num}
    {
    }

    void SetValue(std::optional<double> num)
    {
        m_value = num;
    }

    std::optional<double> GetValue() const override
    {
        return m_value;
    }

    const std::string& GetType() override
    {
        return type;
    }
private:
    inline static const std::string type = "variable";
    std::optional<double> m_value;
};
