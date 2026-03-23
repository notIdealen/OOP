//Calculator
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <array>
#include <optional>
#include <list>

using namespace std;

using VariablesList1 = std::map<std::string, std::string>;
using FunctionsList2 = std::map<std::string, std::vector<std::string>>;
using FunctionsList1 = std::map<std::string, std::array<std::string, 3>>;

using VariablesList = std::map<std::string, double>;
using FunctionsList = std::map<std::string, std::list<std::string>>;

std::optional<double> ConvertStringToDouble(std::string num)
{
    double d;
    try
    {
        d = stod(num);
    }
    catch(const std::exception& e)
    {
        return;
    }
    return d;
}

int main(int argc, char const *argv[])
{
    string line;
    FunctionsList1 fList{{"qwe", {"a", "+", "b"}}};
    std::array<int, 3> ar{};
    
    string num1 = "12a3.321";
    string num2 = "123.32a1";
    string num3 = "123.321a";

    double d = 2.0;
    cout << stod(num1) << endl;
    cout << stod(num2) << endl;
    cout << stod(num3) << endl;
/*
    while (getline(cin, line))
    {
        if (line.empty()) break;

        stringstream ss(line);
        string token = "";
        while (ss >> token)
        {
            cout << token << endl;
        }
    }
*/
    return 0;
}
// g++
// let x = 3
// let y = 4
// fn f1 = x
// fn f2 = f1 + y
// fn f3 = f2 * x
// print f3 -> f2 * x -> (f1 + y) * x -> (3 + 4) * 3 => 21
// let x = 10
// print f3 -> f2 * x -> (f1 + y) * x -> (10 + 4) * 10 => 140
// избавиться от рекурсии создавая польскую нотацию и потом считая её
// *+f1yx or xf1y+*
// f2=x/y/+
// f3 = f2 * x -> 
// use std::list -> fast insert 
// плюсом хранить не стринговые переменные, а ссылки/указатели на значения этих переменных
#include <deque>
