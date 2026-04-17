#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <memory>

#include "catch.hpp"

#include "includes/IShape.hpp"
#include "includes/Controller.hpp"
#include "includes/CCircle.hpp"
#include "includes/CTriangle.hpp"
#include "includes/CRectangle.hpp"
#include "includes/CLineSegment.hpp"
#include "includes/MockCanvas.hpp"

sf::RenderWindow window(sf::VideoMode({10, 10}), "test");

using namespace std;

TEST_CASE("insert new shape")
{
    SECTION("insert circle")
    {
        Controller controller(window); 
        struct TestStruct {
            std::string input;
            bool result;
        };
        auto testData = GENERATE(
            TestStruct{"circle 2.9856 3.96247 2 000001 0000ff", true},
            TestStruct{"circle -2.9856 -3.96247 2 000001 0000ff", true},
            TestStruct{"circle 2.9856 3.96247 -2 000001 0000ff", false},
            TestStruct{" circle 2.9856 3.96247 2 1000000 0000ff", false},
            TestStruct{" circle 2.9856 3.96247 2 00ffaa 0000ff", true},
            TestStruct{"circle 2.9856 3.96247 2 1000000 ", false},
            TestStruct{"ciQcle 2.9856 3.96247 2 000001 1000000", false}
        );
        bool isInsert = controller.InsertShape(testData.input);
        CAPTURE(testData.input);
        REQUIRE(isInsert == testData.result);
    }
    SECTION("insert triangle")
    {
        sf::RenderWindow window(sf::VideoMode({10, 10}), "test");
        Controller controller(window); 
        struct TestStruct {
            std::string input;
            bool result;
        };
        auto testData = GENERATE(
            TestStruct{"triangle 2.9856 3.96247 5.25 7.666 0 0 000001 0000ff", true},
            TestStruct{"triangle -2.9856 -3.96247 -5.25 -7.666 -0 0 000001 0000ff", true},
            TestStruct{"triangle 2.9856 3.96247 5.25 7.666 0 0 1000001 0000ff", false},
            TestStruct{"triangle 2.9856 3.96247 5.25 7.666 0 0 000001 10000ff", false},
            TestStruct{"triaQgle 2.9856 3.96247 5.25 7.666 0 0 000001 10000ff", false},
            TestStruct{"triangle 0 0 1 1 2 2 000001 10000ff", false}
        );
        bool isInsert = controller.InsertShape(testData.input);
        CAPTURE(testData.input);
        REQUIRE(isInsert == testData.result);
    }
    SECTION("insert rectangle")
    {
        sf::RenderWindow window(sf::VideoMode({10, 10}), "test");
        Controller controller(window);  
        struct TestStruct {
            std::string input;
            bool result;
        };
        auto testData = GENERATE(
            TestStruct{"rectangle 2.9856 3.96247 10 15.5 000001 0000ff", true},
            TestStruct{"rectangle -2.9856 -3.96247 10 15.5 000001 0000ff", true},
            TestStruct{"rectangle -2.9856 -3.96247 0 15.5 000001 0000ff", false},
            TestStruct{"rectangle -2.9856 -3.96247 10 0 000001 0000ff", false},
            TestStruct{"rectangle -2.9856 -3.96247 10 15.5 1000001 0000ff", false},
            TestStruct{"rectangle -2.9856 -3.96247 10 15.5 000001 10000ff", false},
            TestStruct{"reQtangle -2.9856 -3.96247 10 15.5 000001 0000ff", false}
        );
        bool isInsert = controller.InsertShape(testData.input);
        CAPTURE(testData.input);
        REQUIRE(isInsert == testData.result);
    }
    SECTION("insert line")
    {
        sf::RenderWindow window(sf::VideoMode({10, 10}), "test");
        Controller controller(window); 
        struct TestStruct {
            std::string input;
            bool result;
        };
        auto testData = GENERATE(
            TestStruct{"line 2.9856 3.96247 10 9.97 0000ff", true},
            TestStruct{"line -2.9856 3.96247 10 -9.97 0000ff", true},
            TestStruct{"line 2.9856 3.96247 10 9.97 10000ff", false},
            TestStruct{"line 2.9856 3.96247 2.9856 3.96247 0000ff", false},
            TestStruct{"liQne 2.9856 3.96247 10 9.97 0000ff", false}
        );
        bool isInsert = controller.InsertShape(testData.input);
        CAPTURE(testData.input);
        REQUIRE(isInsert == testData.result);
    }
}

TEST_CASE("Shape with max area")
{
    sf::RenderWindow window(sf::VideoMode({10, 10}), "test");
    Controller controller(window); 
    string shapes[4]{
        "line 2.9856 3.96247 10 9.97 0000ff",
        "rectangle 0 0 10 15.5 000001 0000ff",
        "triangle 0 0 0 3 4 0 000001 0000ff",
        "circle 2.9856 3.96247 1 000001 0000ff"
    };
    for (auto& sh : shapes)
        controller.InsertShape(sh);

    auto result = 155.00;
    REQUIRE(controller.GetShapeWithMaxArea()->GetArea() == result);
}

TEST_CASE("Shape with min perimeter")
{
    sf::RenderWindow window(sf::VideoMode({10, 10}), "test");
    Controller controller(window); 
    string shapes[4]{
        "line 2.9856 3.96247 10 1000 0000ff",
        "rectangle 0 0 10 15.5 000001 0000ff",
        "triangle 0 0 0 3 4 0 000001 0000ff",
        "circle 2.9856 3.96247 15 000001 0000ff"
    };
    for (auto& sh : shapes)
        controller.InsertShape(sh);

    auto result = 12.00;
    REQUIRE(controller.GetShapeWithMinPerimeter()->GetPerimeter() == result);
}

TEST_CASE("calculate area")
{
    SECTION("circle")
    {
        CCircle circle{0, 0, 1, 0x00ffe0, 0x1100aa};
        double area = CCircle::s_PI * 1 * 1;
        REQUIRE(circle.GetArea() == area);
    }
    SECTION("triangle")
    {
        CTriangle tri{0, 0, 3, 0, 0, 4, 0x00ffe0, 0x1100aa};
        double area = 4 * 3/2;
        REQUIRE(tri.GetArea() == area);
    }
    SECTION("rectangle")
    {
        CRectangle rect{1.58, -2.0008, 10.5, 20, 0x00ffe0, 0x1100aa};
        double area = 10.5 * 20;
        REQUIRE(rect.GetArea() == area);
    }
    SECTION("line")
    {
        CLineSegment line{0, -2, 0, 2, 0x00ffe0};
        double area = 0.0;
        REQUIRE(line.GetArea() == area);
    }
}

TEST_CASE("calculate perimeter")
{
    SECTION("circle")
    {
        CCircle circle{0, 0, 1, 0x00ffe0, 0x1100aa};
        double perim = CCircle::s_PI * 2 * 1;
        REQUIRE(circle.GetPerimeter() == perim);
    }
    SECTION("triangle")
    {
        CTriangle tri{0, 0, 3, 0, 0, 4, 0x00ffe0, 0x1100aa};
        double perim = 4 + 5 + 3;
        REQUIRE(tri.GetPerimeter() == perim);
    }
    SECTION("rectangle")
    {
        CRectangle rect{1.58, -2.0008, 10.5, 20, 0x00ffe0, 0x1100aa};
        double perim = 2 * (10.5 + 20);
        REQUIRE(rect.GetPerimeter() == perim);
    }
    SECTION("line")
    {
        CLineSegment line{0, -2, 0, 2, 0x00ffe0};
        double perim = 4.0;
        REQUIRE(line.GetPerimeter() == perim);
    }
}

TEST_CASE("Print shape")
{
    SECTION("circle")
    {
        CCircle circle{-55.78, 66.6974, 1, 0x00ffe0, 0x1100aa};
        string info = circle.ToString();
        string result = R"(circle:
  center: (-55.78, 66.6974)
  radius: 1
  outline: 00FFE0
  fill: 1100AA
  Area: 3.14
  Perimeter: 6.28
---------------------------
)";
    REQUIRE(info == result);
    }

    SECTION("triangle")
    {
        CTriangle tri{0, 0, 3, 0, 0, 4, 0x00ffe0, 0x1100aa};
        string info = tri.ToString();
        string result = R"(triangle:
  vertex1: (0, 0)
  vertex2: (3, 0)
  vertex3: (0, 4)
  outline: 00FFE0
  fill: 1100AA
  Area: 6.00
  Perimeter: 12.00
---------------------------
)";
    REQUIRE(info == result);
    }

    SECTION("rectangle")
    {
        CRectangle rect{1.58, -2.0008, 10.5, 20, 0x00ffe0, 0x1100aa};
        string info = rect.ToString();
        string result = R"(rectangle:
  Top-left vertex: (1.58, -2.0008)
  width: 10.5
  height: 20
  outline: 00FFE0
  fill: 1100AA
  Area: 210.00
  Perimeter: 61.00
---------------------------
)";
    REQUIRE(info == result);
    }

    SECTION("line")
    {
        CLineSegment line{0, -2, 0, 2, 0x00ffe0};
        string info = line.ToString();
        string result = R"(line:
  start point: (0, -2)
  end point: (0, 2)
  outline: 00FFE0
  Perimeter: 4.00
---------------------------
)";
    REQUIRE(info == result);
    }
}

TEST_CASE("Canvas")
{
    MockCanvas mc;
    mc.DrawCircle({100, 100}, 100, 0x00ff00);
    REQUIRE(mc.m_line == "100 100 100 00ff00");
    mc.DrawLine({100.25, 100.50}, {100, 100}, 0x00ff00);
    REQUIRE(mc.m_line == "100.25 100.5 100 100 00ff00");
    mc.DrawPolygon({{100, 102}, {300, 301}, {500, 500}}, 0x00ff00);
    REQUIRE(mc.m_line == "100 102 300 301 500 500 00ff00");
    mc.FillCircle({100, 100}, 100, 0x00ff00);
    REQUIRE(mc.m_line == "100 100 100 00ff00");
    mc.FillPolygon({{100, 102}, {300, 301}, {500, 500}}, 0x00ff00);
    REQUIRE(mc.m_line == "100 102 300 301 500 500 00ff00");
}
