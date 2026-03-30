#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "includes/Generator.hpp"

using namespace std;

TEST_CASE("primes")
{
    SECTION("upper bound equal 0")
    {
        std::set<int> primes{};
        int upperBound = 0;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("upper bound less 2")
    {
        std::set<int> primes{};
        int upperBound = 1;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("upper bound equal 2")
    {
        std::set<int> primes{2};
        int upperBound = 2;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("upper bound more than 2(equal 3)")
    {
        std::set<int> primes{2, 3};
        int upperBound = 3;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("upper bound more than 2(equal 13)")
    {
        std::set<int> primes{2, 3, 5, 7, 11, 13};
        int upperBound = 13;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("Negative number")
    {
        std::set<int> primes{};
        int upperBound = -1;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
    SECTION("Max upper bound")
    {
        std::set<int> primes{};
        int upperBound = 100'000'000;
        REQUIRE(GeneratePrimeNumbersSet(upperBound).size() == 5761455);
    }
    SECTION("Max upper bound")
    {
        std::set<int> primes{};
        int upperBound = 100'000'001;
        REQUIRE(GeneratePrimeNumbersSet(upperBound) == primes);
    }
}
//ctrl+sh+b
