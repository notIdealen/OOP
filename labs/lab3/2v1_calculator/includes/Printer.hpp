#pragma once

#include <optional>
#include <string>
#include "Storage.hpp"

class Printer
{
public:
    void Print(std::optional<double> num);
    void Print(const Storage& storage, std::optional<double> num);
    
    void PrintAll(const std::string& name, std::optional<double> num);
};
