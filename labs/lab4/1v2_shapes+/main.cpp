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
    cout << "Shape with minimum perimeter is " << controller.GetShapeWithMinPerimeter();
    cout << "Shape with maximum area is " << controller.GetShapeWithMaxArea();

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
    // window.draw(rect);
    // sf::sleep(sf::seconds(5));
    return 0;
}
//Get-Content data/picture.txt | .\START.exe

