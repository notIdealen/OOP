//2147483647
//(-2147483647 - 1)
//-10000000000000000000000000000000
//01111111111111111111111111111111
//g++ radix.cpp -o radix.exe
//radix.exe <from> <to> <value>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

const string RADIXES = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int stringToInt(const string& str, int radix)
{
    int num = 0;
    bool negative = false;
    for (char ch : str)
    {
        if (ch == '-' && !negative) 
        {
            negative = true;
            continue;
        }
        if (int pos = RADIXES.find(ch); radix > pos && pos != string::npos) 
        {
            if (negative)
            {
                if ((INT_MIN + pos) / 10  <= num) num = num * radix - pos;
                else throw runtime_error("INT Overflow");
            }
            else
                if ((INT_MAX - pos) / 10  >= num) num = num * radix + pos;
                else throw runtime_error("INT Overflow");
        }
        else throw runtime_error("INVALID VALUE");
    }
    return num;
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
    if (n == 0) return "0";

    bool negative = false;
    if (n < 0) negative = true;

    string num = "";
    num.reserve(33);
    while (n != 0)
    {
        num += RADIXES[abs(n % radix)];
        n = n / radix;
    }
    if (negative) num += '-';
    reverse(num.begin(), num.end());
    return num;
}

int main(int argc, char const *argv[])
{
    if (argc == 4)
        try
        {
            int from = getRadixFromString(argv[1]);
            int to = getRadixFromString(argv[2]);
            int value = stringToInt(argv[3], from);
            cout << intToString(value, to) << endl;
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
        }
    else
        cout << "INVALID NUMBER OF ARGS";
    return 0;
}
