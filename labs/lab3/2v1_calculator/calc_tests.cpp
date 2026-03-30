#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "includes/InputParser.hpp"

using namespace std;

// TEST_CASE("set expression")
// {
//     SECTION("1 argument")
//     {
//         string s = "exp=x";
//     }
//     SECTION("2 arguments")
//     {
//         string s = "exp = x +y";
//     }
//     SECTION("left argument right expression")
//     {
//         string s = "exp= x+exp1";
//     }
//     SECTION("left expression right argument")
//     {
//         string s = "exp=exp1+x";
//     }
//     SECTION("left expression right expression")
//     {
//         string s = "exp=exp1+exp2";
//     }
// }

TEST_CASE("trim all spaces")
{   
    InputParser cp;
    string s = "  qw e  rt yy   ";
    cp.TrimAllSpaces(s);
    REQUIRE( s == "qwertyy");
}
TEST_CASE("set name")
{   
    InputParser cp;
    string s1 = " xy";
    // cp.TrimAllSpaces(s);
    string s2 = " Ot = x + fn";
    cp.SetName(s1);
    REQUIRE( cp.varName == " xy");
    cp.SetName(s2);
    REQUIRE( cp.varName == " Ot ");
}
TEST_CASE("set values")
{   
    InputParser cp;
    string s0 = " xy";
    cp.SetValues(s0);
    REQUIRE( cp.left.empty());
    cp.ClearFields();
    string s1 = " =xy";
    cp.SetValues(s1);
    REQUIRE( cp.left == "xy");
    REQUIRE(cp.operation.empty());
    REQUIRE(cp.right.empty());
    cp.ClearFields();
    string s2 = " Ot = x / fn";
    cp.SetValues(s2);
    REQUIRE( cp.left == " x ");
    REQUIRE(cp.operation == "/");
    REQUIRE(cp.right == " fn");
}
