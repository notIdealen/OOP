//
//g++ utils/createBin.cpp -o createBin.exe
//utils/cb.exe data/text.txt
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void print()
{
    ifstream in("data/crypt1.bin", ios::binary);
    char ch;

    while (in.get(ch))
    {
        cout << ch << endl;
    }
}


int main(int argc, char const *argv[])
{
    ofstream out("data/text.bin", ios::binary);
    string text;
    getline(cin, text);
    out.write(text.c_str(), text.size());
    // out.write("\nasd text"s.c_str(), "\nasd text"s.size());
    out.close();

    return 0;
}
