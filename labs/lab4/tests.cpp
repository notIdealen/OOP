#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"

#include "includes/Controller.hpp"
// #include <sstream>

using namespace std;

TEST_CASE("IsValid number")
{
    Controller ctl;
    SECTION("NUMBER")
    {
        // struct TestStruct {
        //     std::string token;
        //     double num;
        // };
        // auto testData = GENERATE(
        //     TestStruct{"123.34", 123.34},
        //     TestStruct{"123,34", false},
        //     TestStruct{"123.3as4", false},
        //     TestStruct{"s123.34", false},
        //     TestStruct{" 123.34", false},
        //     TestStruct{" 12 3.34", false}
        // );
        // ctl.IsValidNumber(testData.token,)
        // REQUIRE();
    }
}
