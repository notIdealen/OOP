#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "includes/Calculator.hpp"
#include "includes/Variable.hpp"
#include "includes/Function.hpp"
#include "includes/Expression.hpp"
#include "includes/Controller.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Calculator tests")
{
    SECTION("Valid name")
    {
        Calculator calc;
        struct TestCase 
        {
            string input;
            bool result;
        };
        auto testData = GENERATE(
            TestCase{"", false},
            TestCase{"9qwer", false},
            TestCase{"asd", true},
            TestCase{"AsdDr", true},
            TestCase{"AsdDr", true},
            TestCase{"As_dDr", true},
            TestCase{"As_dD91r", true},
            TestCase{" As_dD91r", false},
            TestCase{"as!@r", false}
        );
        REQUIRE(calc.IsValidName(testData.input) == testData.result);
    }
    SECTION("string to double")
    {
        Calculator calc;
        struct TestCase 
        {
            string input;
            optional<double> result;
        };
        auto testData = GENERATE(
            TestCase{"", nullopt},
            TestCase{"9qwer", 9},
            TestCase{"84.697", 84.697},
            TestCase{"s555", nullopt},
            TestCase{" 34.97", nullopt}
        );
        REQUIRE(calc.ToDouble(testData.input) == testData.result);
    }
    SECTION("is name exist")
    {
        Calculator calc;
        calc.PutInStorage("var1", std::make_shared<Variable>(1));
        calc.PutInStorage("var2", std::make_shared<Variable>(2));

        struct TestCase 
        {
            string input;
            bool result;
        };
        auto testData = GENERATE(
            TestCase{"var1", true},
            TestCase{"var3", false}
        );
        REQUIRE(calc.IsNameExist(testData.input) == testData.result);
    }
    SECTION("put in storage")
    {
        Calculator calc;
        calc.PutInStorage("var1", std::make_shared<Variable>(1));

        CHECK_THROWS(calc.PutInStorage("var1", std::make_shared<Variable>(1)));
        CHECK_NOTHROW(calc.PutInStorage("var3", std::make_shared<Variable>(3)));
    }
    SECTION("check let command")
    {
        Calculator calc;
        calc.PutInStorage("var1", std::make_shared<Variable>(1));
        calc.PutInStorage("var2", std::make_shared<Variable>(2));
        auto storage = calc.GetStorage();
        calc.PutInStorage("f1", std::make_shared<Function>(storage["var1"]));
        string s1 = "var1";
        string s2 = "var2";
        string f1 = "f1";
        optional<double> d = 99.0;
        calc.RunLetCommand(s1, s2);
        REQUIRE(storage["var1"]->GetValue().value() == 2);
    }
}

TEST_CASE("Parsing string")
{
    Parser p;
    struct TestCase
    {
        string input;
        std::string command{};
        std::string name{};
        std::string lValue{};
        std::string operation{};
        std::string rValue{};

    };
    auto testData = GENERATE(
        TestCase{"","","","","",""},
        TestCase{"  comm   ", "comm", "", "", "", ""},
        TestCase{"  comm  qw ", "comm", "qw", "", "", ""},
        TestCase{"  comm  qw  =  ", "comm", "qw", "", "", ""},
        TestCase{"  comm  qw  =  -5 ", "comm", "qw", "-5", "", ""},
        TestCase{"  comm  qw  =  F ", "comm", "qw", "F", "", ""},
        TestCase{"  comm  qw  =  F+", "comm", "qw", "F", "+", ""},
        TestCase{"  comm  qw  =  F+v", "comm", "qw", "F", "+", "v"}
    );

    p.Parse(testData.input);
    REQUIRE((
        p.command == testData.command &&
        p.name == testData.name &&
        p.lValue == testData.lValue &&
        p.operation == testData.operation &&
        p.rValue == testData.rValue
    ));
}

TEST_CASE("Calculation")
{
    Calculator calc;
    SECTION("cache test")
    {
        // calc.PutInStorage()
    }
    SECTION("closure")
    {
    }
}


