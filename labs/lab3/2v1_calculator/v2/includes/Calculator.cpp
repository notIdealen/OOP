#include "Calculator.hpp"
#include "Variable.hpp"
#include "Function.hpp"
#include <regex>
#include <charconv>

bool IsValidName(const std::string& name)
{
    std::regex pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
    return std::regex_match(name, pattern);
}

bool IsValidOperation(const char& currOperation)
{
    for (const char& op : Calculator::validOperations)
        if (op == currOperation)
            return true;
    return false;
}

std::optional<double> ToDouble(const std::string& token)
{
    double d;
    auto [ptr, ec] = std::from_chars(token.data(), token.data() + token.size(), d);
    if (ec == std::errc{})
        return d;
    return std::nullopt;
}

// void Calculator::PutInCache(const std::string name, std::optional<double> value)
// {
//     cache[name] = value;
// }

void Calculator::PutInStorage(const std::string name, std::shared_ptr<Expression> exp)
{
    if (storage.find(name) != storage.end())
        throw std::invalid_argument("Name already exists: " + name);
    storage[name] = exp;
}

void Calculator::RunVarCommand(std::string& name)
{
    if (!IsValidName(name))
        throw std::invalid_argument("Invalid usage var: " + name);

    PutInStorage(name, std::make_shared<Variable>(std::nullopt));
}

void Calculator::RunLetCommand(std::string& name, std::string& lValue)
{
    if (!IsValidName(name))
        throw std::invalid_argument("Invalid usage let: " + name);
    
    if (auto num = ToDouble(lValue); num != std::nullopt)
    {
        if (auto it = storage.find(name); it != storage.end())
            dynamic_cast<Variable*>(storage.at(name).get())->SetValue(num.value());
        else
            PutInStorage(name, std::make_shared<Variable>(num.value()));
        return;
    }

    if (storage.find(lValue) == storage.end())
        throw std::invalid_argument("Name does not exist: " + lValue);

    if (storage[lValue]->GetType() == Expression::ExpressionType::variable)
    {
        PutInStorage(name, std::make_shared<Variable>(storage[lValue]->GetValue()));
    }
}

void Calculator::RunFnCommand(std::string& name, std::string& lValue, std::string& operation, std::string& rValue)
{
    if (!IsValidName(name))
        throw std::invalid_argument("Invalid usage fn: " + name);

    if (!IsValidName(lValue))
        throw std::invalid_argument("Invalid usage fn: " + lValue);

    if (operation == "" && rValue == "")
    {
        if (storage.find(lValue) == storage.end())
            throw std::invalid_argument("Name does not exist: " + lValue);

        if (storage[lValue]->GetType() == Expression::ExpressionType::variable)
        {
            PutInStorage(name, std::make_shared<Function>(storage[lValue]));
            cache[name][lValue] = storage[lValue]->GetValue();
            // PutInCache(name, storage[lValue]->GetValue());////////////////////////////////
        }
        else if (storage[lValue]->GetType() == Expression::ExpressionType::function)
            PutInStorage(name, std::make_shared<Function>(storage[lValue]));
        return;
    }

    if (operation != "" && rValue != "")
    {
        if (!IsValidName(rValue))
            throw std::invalid_argument("Invalid usage fn: " + rValue);
        
        if (storage.find(rValue) == storage.end())
            throw std::invalid_argument("Name does not exist: " + lValue);

        if (!IsValidOperation(operation[0]))
            throw std::invalid_argument("Invalid usage fn: " + rValue);

        PutInStorage(name, std::make_shared<Function>(storage[lValue], storage[rValue], operation[0]));
        return;
    }
    throw std::invalid_argument("Invalid usage fn:");
}
