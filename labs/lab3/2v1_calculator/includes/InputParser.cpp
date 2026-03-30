#include "InputParser.hpp"

void InputParser::TrimAllSpaces(std::string& s)
{
    s.erase(std::remove(s.begin(),s.end(),' '),s.end());
}

void InputParser::TrimStartSpaces(std::string& s)
{
    size_t start = s.find_first_not_of(' ');
    if (start == std::string::npos)
    {
        s = "";
        return;
    }
    s = s.substr(start);
}

void InputParser::TrimCommand(std::string& line)
{
    TrimStartSpaces(line);
    size_t end = line.find(' ');
    if (end == std::string::npos)
    {
        command = line;
        return;
    }
        command = line.substr(0, end);
    line = line.substr(end);
}

void InputParser::SetName(std::string& line)
{
    size_t end = line.find_first_of('=');
    varName = line.substr(0, end);
}

void InputParser::SetValues(std::string& line)
{
    if (line.size() == 0)
        return;
    size_t start = line.find_first_of('=');
    if (start == std::string::npos)
        return;
    ++start;
    if (line.begin() + start == line.end())
        return;

    size_t end = line.find_first_of("+/-*", start + 1);
    if (end == std::string::npos)
    {
        left = line.substr(start);
        return;
    }

    left = line.substr(start, end - start);
    if (line.begin() + end + 1 == line.end()) 
        return;
    operation = line[end];
    right = line.substr(end + 1);
}

void InputParser::ClearFields()
{
    command = varName = left = right = operation = "";
}
