#pragma once

#include "Parser.hpp"
#include "Printer.hpp"
#include "Calculator.hpp"

class Controller
{
public:
    void ReadLine(const std::string& line);

    void RunCommand();
    

private:
    Parser parser;
    Printer printer;
    Calculator calc;
};
