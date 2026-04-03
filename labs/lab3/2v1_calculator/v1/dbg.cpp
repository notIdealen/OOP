#include <iostream>
#include <string>

#include "includes/InputParser.hpp"
#include "includes/Parser.hpp"

using namespace std;

void Print(Parser& p)
{
    cout << '>' << p.command << '<' << endl;
    cout << '>' << p.name << '<' << endl;
    cout << '>' << p.lValue << '<' << endl;
    cout << '>' << p.operation << '<' << endl;
    cout << '>' << p.rValue << '<' << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Parser p;
    string s0 = "comm  ";
    string s1 = "asdf Owt   ";
    string s2 = "zxC xxx = ui   ";
    string s3 = "let re = -   987   ";
    string s4 = "Qwerty Ot = x / fn";
    // p.Parse(s0);
    p.Parse(s0);
    Print(p);
    p.Parse(s1);
    Print(p);
    p.Parse(s2);
    Print(p);
    p.Parse(s3);
    Print(p);
    p.Parse(s4);
    Print(p);

    return 0;
}


