#pragma once

#include <memory>
#include "Storage.hpp"
#include "Expression.hpp"
#include "Parser.hpp"
#include "Cache.hpp"



class Calculator
{
public:
    void RunVarCommand(std::string& name);
    void RunLetCommand(std::string& name, std::string& lValue);
    void RunFnCommand(std::string& name, std::string& lValue, std::string& operation, std::string& rValue);

    const Storage& GetStorage()
    {
        return storage;
    }
    const Cache& GetCache()
    {
        return cache;
    }

    inline static const char validOperations[4] = {'+', '-', '*', '/'};
private:
    void PutInStorage(const std::string name, std::shared_ptr<Expression> exp);
    // void PutInCache(const std::string name, std::optional<double> value);

    Storage storage{};
    Cache cache;
};

