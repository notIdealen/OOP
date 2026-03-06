#define CATCH_CONFIG_MAIN
#include "includes/decodehtml.cpp"

#include <iostream>

#include "catch/catch.hpp"

using namespace std;

TEST_CASE("Simple test")
{
    const string html =
        "&lt;H1&gt;Main &&&;; title &amp &amp; &lA book &QUOT name&lt;/H1&gt;\n"
        "&lt;p&gt;&quot;Some&quot; text for me &apos;In "
        "Apostrofs:&quot;+&apos;+&lt;+&gt;+&amp;&lt;/p&gt;\n"
        "&lt";
    const string result =
        "<H1>Main &&&;; title &amp & &lA book &QUOT name</H1>\n"
        "<p>\"Some\" text for me 'In Apostrofs:\"+'+<+>+&</p>\n"
        "&lt";
    REQUIRE(DecodeHTML(html) == result);
}

TEST_CASE("Empty string")
{
    const string html = "";
    const string result = "";
    REQUIRE(DecodeHTML(html) == result);
}

TEST_CASE("Get entity")
{
    string entity1 = "&quot;";
    size_t i1 = 0;
    REQUIRE(GetEntity(entity1, i1) == "&quot;");
    string entity2 = "qwe&quot;";
    size_t i2 = 3;
    REQUIRE(GetEntity(entity2, i2) == "&quot;");
    string entity3 = "qwe&quot;";
    size_t i3 = 0;
    REQUIRE(GetEntity(entity3, i3) == "&we");
    string entity4 = "&";
    size_t i4 = 0;
    REQUIRE(GetEntity(entity4, i4) == "&");
    string entity5 = "&&&;;";
    size_t i5 = 0;
    REQUIRE(GetEntity(entity5, i5) == "&");
}

TEST_CASE("Insert entity")
{
    string html1 = "<H1>";
    InsertEntity(html1, "&quot;");
    REQUIRE(html1 == "<H1>\"");
    string html2 = "<H1>";
    InsertEntity(html2, "&quot");
    REQUIRE(html2 == "<H1>&quot");
}

// g++ decodehtml_test.cpp -o tests.exe
