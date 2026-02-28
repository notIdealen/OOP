//
//g++ utils/createBinMS.cpp -o createBinMS.exe
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
    ifstream in("data/kniga.txt");
    ofstream out("data/textMS.bin", ios::binary);
    string text;
    while (getline(in, text))
    {
        out.write(text.c_str(), text.size());
    }
    // out.write("\nasd text"s.c_str(), "\nasd text"s.size());
    out.close();
    in.close();

    return 0;
}
