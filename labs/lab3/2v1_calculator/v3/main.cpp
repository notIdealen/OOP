// Calculator
#include <iostream>
#include "includes/Controller.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Controller controller;
    std::string line;
    while (getline(cin, line))
    {
        if (line.empty()) break;
        controller.ReadLine(line);
        try
        {
            controller.RunCommand();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        
    }
    return 0;
}
//Get-Content data/set1.txt | .\calc.exe
//Get-Content data/fibo.txt | .\calc.exe
