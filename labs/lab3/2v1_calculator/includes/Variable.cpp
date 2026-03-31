#include "Variable.hpp"

Variable::Variable(std::optional<double> num) : m_value{num}
{
}

void Variable::SetValue(std::optional<double> num)
{
    m_value = num;
}

std::optional<double> Variable::GetValue() const
{
    return m_value;
}

Expression::ExpressionType Variable::GetType()
{
    return type;
}
