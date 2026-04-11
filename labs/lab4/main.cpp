//
#include <iostream>
#include "includes/Controller.hpp"

using namespace std;
//print color!!!
//CLineSegment create
int main(int argc, char const *argv[])
{
    Controller controller;
    std::string line;
    while (getline(cin, line))
    {
        if (line.empty()) break;
        try
        {
            controller.InsertShape(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    controller.PrintShapes();
    cout << "Shape with minimum perimeter is " << controller.GetShapeWithMinPerimeter();
    cout << "Shape with maximum area is " << controller.GetShapeWithMaxArea();
    return 0;
}
//Get-Content data/shapes.txt | .\START.exe
