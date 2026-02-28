//
//g++
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ofstream out("ms.txt");
    string temp = "";
    temp.reserve(1000'000);
    for (size_t i = 0; i < 1'000'000; ++i)
    {
        temp += 'a';
    }
    out << temp;
    out.close();
    return 0;
}
