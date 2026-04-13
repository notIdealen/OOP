//
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
        if (!controller.InsertShape(line))
            cout << "Shape dont insert.\n";

    }
    controller.PrintShapes(std::cout);
    cout << "Shape with minimum perimeter is " << controller.GetShapeWithMinPerimeter();
    cout << "Shape with maximum area is " << controller.GetShapeWithMaxArea();
    return 0;
}
//Get-Content data/shapes.txt | .\START.exe
