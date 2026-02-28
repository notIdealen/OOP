#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch/catch.hpp"
#include "includes/translation.hpp"

using namespace std;

TEST_CASE("Get word from input")
{
    cout << "Input 'slon', input '...' and input empty string" << endl;
    REQUIRE(GetWord() == "slon");
    REQUIRE(GetWord() == "...");
    REQUIRE(GetWord() == "");
}

TEST_CASE("Save word to dictionary")
{
    Dictionary dic;
    string word = "new Word";
    cout << "Enter 'qwerty' as translation:" << endl;
    REQUIRE(SaveWord(dic, word) == "qwerty");
    REQUIRE(dic.find(word) != dic.end());
    cout << "Enter empty string as translation" << endl;
    REQUIRE(SaveWord(dic, word) == "");
    REQUIRE(dic.find("") == dic.end());
}


// g++ dic_tests.cpp includes/translation.cpp -o tests.exe
