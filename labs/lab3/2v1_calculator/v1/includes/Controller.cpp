#include <stdexcept>
#include "Controller.hpp"
#include "Storage.hpp"


void Controller::ReadLine(const std::string& line)
{
    parser.Parse(line);
}

void Controller::RunCommand()
{
    if (parser.command == "var")
        calc.RunVarCommand(parser.name);
    else if (parser.command == "let")
        calc.RunLetCommand(parser.name, parser.lValue);
    else if (parser.command == "fn")
        calc.RunFnCommand(parser.name, parser.lValue, parser.operation, parser.rValue);
    else if (parser.command == "print")
    {
        Storage storage = calc.GetStorage();
        if (storage.find(parser.name) == storage.end())
            throw std::invalid_argument("Name does not exist: " + parser.name);
        printer.Print(storage[parser.name]->GetValue());
    }
    else if (parser.command == "printvars")
    {
        Storage storage = calc.GetStorage();
        for (const auto& [key, expression] : storage)
            if (expression->GetType() == Expression::ExpressionType::variable)
                printer.PrintAll(key, expression->GetValue());
    }
    else if (parser.command == "printfns")
    {
        Storage storage = calc.GetStorage();
        for (const auto& [key, expression] : storage)
            if (expression->GetType() == Expression::ExpressionType::function)
                printer.PrintAll(key, expression->GetValue());
    }
    else
        throw std::invalid_argument("Unknown command");
}
