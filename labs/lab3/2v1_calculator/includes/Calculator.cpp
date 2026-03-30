#include "Calculator.hpp"
#include "Variable.hpp"
#include <regex>
#include <charconv>
// #include <string>
// #include <iostream>

bool IsValidName(const std::string& name)
{
    std::regex pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
    return std::regex_match(name, pattern);
}

std::optional<double> ToDouble(const std::string& token)
{
    double d;
    auto [ptr, ec] = std::from_chars(token.data(), token.data() + token.size(), d);
    if (ec == std::errc{})
        return d;
    return std::nullopt;
}

void Calculator::PutInStorage(const std::string name, std::unique_ptr<Expression> exp)
{
    if (storage.find(name) != storage.end())
        throw std::invalid_argument("Name already exists: " + name);
    storage[name] = std::move(exp);
}

void Calculator::RunVarCommand(Parser& parser)
{
    if (!IsValidName(parser.name))
        throw std::invalid_argument("Invalid usage: " + parser.name);

    PutInStorage(parser.name, std::make_unique<Variable>(std::nullopt));
}

void Calculator::RunLetCommand(Parser& parser)
{
    if (!IsValidName(parser.name) || !parser.operation.empty() || !parser.rValue.empty())
        throw std::invalid_argument("Invalid usage: " + parser.name);
    
    if (auto num = ToDouble(parser.lValue); num != std::nullopt)
    {
        PutInStorage(parser.name, std::make_unique<Variable>(num.value()));
        return;
    }

    if (storage.find(parser.lValue) == storage.end())
    throw std::invalid_argument("Name does not exist: " + parser.lValue);

    if (storage[parser.lValue]->GetType() == "variable")
    {
        PutInStorage(parser.name, std::make_unique<Variable>(storage[parser.lValue]->GetValue()));
    }
}

void Calculator::RunFnCommand(Parser& parser)
{
    if (!IsValidName(parser.name))
        throw std::invalid_argument("Invalid usage: " + parser.name);

}

void Calculator::RunPrintCommand(Parser& parser, Printer& printer)
{
    if (!IsValidName(parser.name))
        throw std::invalid_argument("Invalid usage: " + parser.name);
    
    if (storage.find(parser.name) == storage.end())
        throw std::invalid_argument("Name does not exist: " + parser.name);
        
    printer.Print(storage[parser.name]->GetValue());
}

void Calculator::RunPrintvarsCommand(Parser& parser, Printer& printer)
{
    for (const auto& [key, expression] : storage)
        printer.Print(expression->GetValue());
}
// void RunPrintfnsCommand(Parser& parser);




// void Calculator::ParseLine(std::string line)
// {
//     parser.TrimCommand(line);
//     parser.TrimAllSpaces(line);
//     if (parser.command == "var")
//     {
//         parser.SetName(line);
//         // std::cout << "name:" << parser.varName << std::endl;
//         if (IsValidName(parser.varName))
//         {
//             PutInStorage(std::make_unique<Variable>(std::nullopt));
//         }
//         parser.ClearFields();
//         return;
//     }
//     if (parser.command == "let")
//     {
//         parser.SetName(line);
//         parser.SetValues(line);
//         // std::cout << "name:" << parser.varName << std::endl;
//         auto num = ConvertStringToDouble(parser.left);
//         // std::cout << "values:" << parser.left << ' ' << num.value() << std::endl;
//         if (num != std::nullopt)
//         {
//             if (IsValidName(parser.varName))
//             {
//                 if (storage.find(parser.left) != storage.end() && storage[parser.left]->GetType() == "variable")
//                 {
//                     auto* ptr = storage[parser.left].get();
//                     Variable* var = static_cast<Variable*>(ptr);
//                     var->SetValue(num);
//                     return;
//                 }
//                 PutInStorage(std::make_unique<Variable>(num));
//             }
//             parser.ClearFields();
//             return;
//         }
//         if (storage.find(parser.left) != storage.end())
//             PutInStorage(std::make_unique<Variable>(storage[parser.left]->GetValue()));
//         parser.ClearFields();
//         return;
//     }
//     if (parser.command == "fn"){}
//     if (parser.command == "print")
//     {
//         // std::cout << storage.size() << std::endl;
//         for (const auto& [k, v] : storage)
//         {
//             std::cout << k << ':';
//             if (auto res = v->GetValue(); res != std::nullopt)
//                 std::cout << res.value() << std::endl;
//             else
//                 std::cout << "nan" << std::endl;
//         }
//     }
//     if (parser.command == "printvars")
//     {

//     }
//     if (parser.command == "printfns"){}
// }
