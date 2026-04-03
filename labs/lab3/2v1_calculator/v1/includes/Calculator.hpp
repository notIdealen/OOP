#pragma once

#include <memory>
#include "Storage.hpp"
#include "Expression.hpp"
#include "Parser.hpp"

class Calculator
{
public:
    void RunVarCommand(std::string& name);
    void RunLetCommand(std::string& name, std::string& lValue);
    void RunFnCommand(std::string& name, std::string& lValue, std::string& operation, std::string& rValue);
    const Storage& GetStorage();
    void PutInStorage(const std::string name, std::shared_ptr<Expression> exp);
    bool IsValidName(const std::string& name);
    bool IsValidOperation(const char& currOperation);
    std::optional<double> ToDouble(const std::string& token);
    bool IsNameExist(const std::string& name);

private:
    inline static const char validOperations[4] = {'+', '-', '*', '/'};
    Storage storage{};
};

