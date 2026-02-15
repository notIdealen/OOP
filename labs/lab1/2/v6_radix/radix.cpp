//g++ radix.cpp -o radix.exe
//radix.exe <from> <to> <value>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const string RADIXES = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int stringToInt(const string& str, int radix)
{
    int num = 0;
    bool negative = false;
    for (char ch : str)
    {
        if (ch == '-') 
        {
            negative = true;
            continue;
        }
        if (size_t pos = RADIXES.find(ch); radix > pos && 
            pos != string::npos) num = num * radix + pos;
        else throw runtime_error("WRONG VALUE");
    }
    return negative ? -num : num;
}

int getRadixFromString(string str)
{
    for (char ch : str)
        if (ch < '0' || ch > '9') throw runtime_error("WRONG RADIX");

    int num = stringToInt(str, 10);
    if (num < 2 || num > 35) throw runtime_error("WRONG RADIX");

    return num;
}

string intToString(int n, int radix)
{
    bool negative = false;
    if (n < 0) {negative = true; n = -n;}
    string num = "";
    while (n != 0)
    {
        num += RADIXES[n % radix];
        n = n / radix;
    }
    negative ? num += '-' : num;
    reverse(num.begin(), num.end());
    return num;
}

int main(int argc, char const *argv[])
{
    string fromArg = "10";
    string toArg = "35";
    string valueArg = "255";

    try
    {
        int from = getRadixFromString(fromArg);
        int to = getRadixFromString(toArg);
        int value = stringToInt(valueArg, from);
        cout << "Final:" << intToString(value, to) << endl;
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
