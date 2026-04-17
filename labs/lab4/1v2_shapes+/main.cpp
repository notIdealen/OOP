#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "includes/Controller.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode({600, 600}), "Picture");
    Controller controller(window);
    std::string line;
    while (getline(cin, line))
    {
        if (line.empty()) break;
        if (!controller.InsertShape(line))
            cout << "Shape dont insert.\n";
    }
    controller.PrintShapes(std::cout);
    if (IShape* minPerimeter = controller.GetShapeWithMinPerimeter(); minPerimeter)
        cout << "Shape with minimum perimeter: " << fixed << setprecision(2) << minPerimeter->GetPerimeter() << endl;
    else
        cout << "No Shapes in storage.\n";
        
    if (IShape* maxArea = controller.GetShapeWithMaxArea(); maxArea)
        cout << "Shape with maximum area: " << fixed << setprecision(2) << maxArea->GetArea() << endl;
    else
        cout << "No Shapes in storage.\n";

    while (window.isOpen())
    {
        while (const std::optional ev = window.pollEvent())
        {
            if (ev->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        controller.DrawAllShapes();
        window.display();
    }
    return 0;
}
//Get-Content data/picture.txt | .\START.exe

