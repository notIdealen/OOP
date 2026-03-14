#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch/catch.hpp"
#include "Utils.hpp"

using namespace std;

TEST_CASE("Trime spaces")
{
    string test1 = "  qw e   ";
    TrimSpaces(test1);
    REQUIRE(test1 == "qw e");
    string test2 = "  ";
    TrimSpaces(test2);
    REQUIRE(test2 == "");
}
