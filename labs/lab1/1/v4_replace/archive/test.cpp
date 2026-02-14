//g++ test.cpp -o t.exe
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
    string s = "qwerty\n"
               "asderfgh\n"
               "zxercvbn!";

    // auto x = s.find('e');
    string pattern = "er";
    string filler = "@@@@";
    int c = 0;
    size_t pos = 0;
    while ((pos = s.find(pattern, pos)) != string::npos)
    {
        s.replace(pos, pattern.length(), filler);
        ++pos;
    }
    cout << s << endl;

    return 0;
}

