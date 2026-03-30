#pragma once

#include <string>
#include <array>
#include <sstream>
#include <string>
#include <algorithm>
#include <charconv>


struct InputParser
{
    void TrimAllSpaces(std::string& s);


    void TrimStartSpaces(std::string& s);

    void TrimCommand(std::string& line);


    void SetName(std::string& line);

    void SetValues(std::string& expression);

    void ClearFields();

    std::string command{};
    std::string varName{};
    std::string left{};
    std::string right{};
    std::string operation{};
};
