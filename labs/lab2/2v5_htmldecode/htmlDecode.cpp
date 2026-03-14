#include <iostream>
#include <map>
#include "includes/Decodehtml.hpp"

using namespace std;

int main(int argc, char const* argv[])
{
    string htmlDecodeLine;
    string line;
    while (getline(cin, line))
    {
        if (line == "") break;
        htmlDecodeLine.append(DecodeHTML(line)).append("\n");
    }
    cout << htmlDecodeLine << endl;
    return 0;
}
// g++ htmlDecode.cpp includes/Decodehtml.cpp -o decode.exe
// .\decode.exe data/in.txt > data/out.txt
// Get-Content data/in.txt | .\decode.exe | Out-File data/out.txt
