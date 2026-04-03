#pragma once

#include <optional>
#include <string>
#include <map>
#include <stdexcept>

using VariablesList = std::map<std::string, std::optional<double>>;

class Expression
{
public:
    enum class ExpressionType: char 
    { 
        function = 'f',
        variable = 'v'
    };
    
    virtual std::optional<double> GetValue() const = 0;
    virtual ExpressionType GetType() = 0;
    virtual VariablesList& GetVariablesList(){ throw std::runtime_error("Call on variable type");}
    virtual std::optional<double>& GetCache(){ throw std::runtime_error("Call on variable type");}

    virtual ~Expression() = default;

};
