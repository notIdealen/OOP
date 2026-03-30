#include "Utils.hpp"
#include "algorithm"

using namespace std;

void TrimSpaces(string& s)
{
    size_t start = s.find_first_not_of(' ');
    if (start == string::npos)
    {
        s = "";
        return;
    }
    size_t end = s.find_last_not_of(' ');
    s = s.substr(start, end - start + 1);
}

void TrimAllSpaces(std::string& s)
{
    s.erase(std::remove(s.begin(),s.end(),' '),s.end());
}
