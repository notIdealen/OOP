#pragma once

#include <iostream>
#include <optional>

class Printer
{
public:
    void Print(std::optional<double> num)
    {
        // std::cout << ">" << "!!!!!!!!!" << "<" << std::endl;
        std::cout << ">" << num.value() << "<" << std::endl;
    }

private:
};
