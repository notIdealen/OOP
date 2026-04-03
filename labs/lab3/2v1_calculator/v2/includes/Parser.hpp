#pragma once

#include <string>

class Parser
{
public:
    void Parse(const std::string& line);

    std::string command{};
    std::string name{};
    std::string lValue{};
    std::string operation{};
    std::string rValue{};
};
