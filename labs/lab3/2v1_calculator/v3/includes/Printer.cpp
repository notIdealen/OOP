#include "Printer.hpp"
#include <iostream>
#include <iomanip>

void Printer::Print(std::optional<double> num)
{
    if (num.has_value())
        std::cout << std::fixed << std::setprecision(2) << num.value() << std::endl;
    else
        std::cout << ">nan<" << std::endl;
}

void Printer::PrintAll(const std::string& name, std::optional<double> num)
{
    std::cout << name << ":";
    if (num.has_value())
        std::cout  << std::fixed << std::setprecision(2) << num.value() << std::endl;
    else
        std::cout << ">nan<" << std::endl;
}

