#include "Utils.hpp"

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
