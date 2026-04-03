#include "Parser.hpp"

#include <sstream>

void TrimSpaces(std::string& s)
{
    size_t start = s.find_first_not_of(' ');
    if (start == std::string::npos)
    {
        s = "";
        return;
    }
    size_t end = s.find_last_not_of(' ');
    s = s.substr(start, end - start + 1);
}

void deleteSpaces(std::string& s)
{
    std::string result;
    result.reserve(s.length());
    for (const char ch : s)
        if (ch != ' ')
            result += ch;
    s = std::move(result); 
}

void Parser::Parse(const std::string& line)
{
    command = name = lValue = operation = rValue = "";

    std::stringstream ss(line);
    ss >> command;
    if (std::getline(ss, name, '='))
    {
        TrimSpaces(name);
    }
    if (std::getline(ss, lValue))
    {
        size_t posOperation = lValue.find_first_of("+-*/");
        size_t pos = lValue.find_first_not_of("+- ");
        if (posOperation == std::string::npos || pos > posOperation)
        {
            TrimSpaces(lValue);
            return;
        }
        operation = lValue[posOperation];
        if (posOperation != lValue.size() - 1)
        {
            rValue = lValue.substr(posOperation + 1);
            TrimSpaces(rValue);
        }
        lValue = lValue.substr(0, posOperation);
        TrimSpaces(lValue);
    }
}
