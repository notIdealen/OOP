#pragma once

// #include <regex>
#include "Parser.hpp"
#include "Printer.hpp"
#include "Calculator.hpp"

class Controller
{
public:
    // bool IsValidCommand(const std::string& currCommand)
    // {
    //     return validCommands.find(currCommand) != validCommands.end();
    // }

    // bool IsValidName(const std::string& name)
    // {
    //     std::regex pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
    //     return std::regex_match(name, pattern);
    // }

    void ReadLine(const std::string& line)
    {
        parser.Parse(line);
    }

    void RunCommand()
    {
        if (parser.command == "var")
            calc.RunVarCommand(parser);
        else if (parser.command == "let")
            calc.RunLetCommand(parser);
        else if (parser.command == "fn")
            calc.RunFnCommand(parser);
        else if (parser.command == "print")
            calc.RunPrintCommand(parser, printer);
        else if (parser.command == "printvars")
            calc.RunPrintvarsCommand(parser, printer);
        // else if (parser.command == "printfns")
        //     calc.RunPrintfnsCommand(parser);
        else
            throw std::invalid_argument("Unknown command");
    }
private:
    Parser parser;
    Printer printer;
    Calculator calc;
    // inline static const std::set<std::string> validCommands{"var", "let", "fn", "print", "printvars", "printfns"};

    //Printer printer;
};
