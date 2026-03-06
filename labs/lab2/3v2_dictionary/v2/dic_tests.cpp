#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch/catch.hpp"
#include "includes/bitranslation.cpp"
#include <sstream>

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
    MultiDictionary dic;
    string word = "new Word";
    cout << "Enter 'qwerty' as translation:" << endl;
    REQUIRE(SaveWord(dic, word) == "qwerty");
    REQUIRE(dic.find(word) != dic.end());
    cout << "Enter empty string as translation" << endl;
    REQUIRE(SaveWord(dic, word) == "");
    REQUIRE(dic.find("") == dic.end());
}

TEST_CASE("Load dictionary")
{
    MultiDictionary dic;
    string invalidPath = "qwerty/dic.txt";
    REQUIRE_THROWS_AS(
        LoadDictionary(invalidPath, dic),
        std::runtime_error
    );
    string path = "dic.txt";
    LoadDictionary(path, dic);
    REQUIRE(dic.empty() != true);
}

TEST_CASE("Print translation")
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    MultiDictionary dic;
    string path = "dic.txt";
    LoadDictionary(path, dic);
    std::streambuf* original = std::cout.rdbuf();  // Сохраняем оригинал
    std::ostringstream captured;                   // Буфер для перехвата
    std::cout.rdbuf(captured.rdbuf());             // Перенаправляем cout
    PrintTranslation(dic, "dog");
    std::cout.rdbuf(original);                     // Восстанавливаем cout
    REQUIRE(captured.str() == "собака, собачка\n");
}

TEST_CASE("Save dictionary")
{
    MultiDictionary dic;
    string path = "dic.txt";
    LoadDictionary(path, dic);
    string invalidPath = "qwerty/dic.txt";
    REQUIRE_THROWS_AS(
        SaveDictionary(invalidPath, dic),
        std::runtime_error
    );
    path = "dicTemp.txt";
    SaveDictionary(path, dic);
    LoadDictionary(path, dic);
    REQUIRE(dic.empty() != true);
}

TEST_CASE("Trime spaces")
{
    string test1 = "  qw e   ";
    TrimSpace(test1);
    REQUIRE(test1 == "qw e");
    string test2 = "  ";
    TrimSpace(test2);
    REQUIRE(test2 == "");
}

// g++ dic_tests.cpp -o tests.exe
