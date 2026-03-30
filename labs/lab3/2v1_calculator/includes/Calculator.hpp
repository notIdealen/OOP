#pragma once

#include <memory>
#include "Storage.hpp"
#include "Expression.hpp"
#include "Parser.hpp"
#include "Printer.hpp"

class Calculator
{
public:
    void RunVarCommand(Parser& parser);
    void RunLetCommand(Parser& parser);
    void RunFnCommand(Parser& parser);
    void RunPrintCommand(Parser& parser, Printer& printer);
    void RunPrintvarsCommand(Parser& parser, Printer& printer);
    // void RunPrintfnsCommand(Parser& parser);
    
private:
    void PutInStorage(const std::string name, std::unique_ptr<Expression> exp);

    Storage storage{};
    std::optional<double> value{};
};

