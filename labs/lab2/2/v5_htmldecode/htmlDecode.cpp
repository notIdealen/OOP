//
// g++ htmlDecode.cpp -o decode.exe
#include <iostream>
#include <sstream>

using namespace std;

void ReplaceSpecialText(string& line, string code, string ch)
{
    size_t pos{};
    while ((pos = line.find(code, pos)) != string::npos)
    {
        line.replace(pos, code.length(), ch);
        pos += ch.length();
    }
}

string HtmlDecode(string const& html)
{
    string decodeLine;
    string decodeHTML;
    stringstream ss(html);
    while (getline(ss, decodeLine))
    {
        ReplaceSpecialText(decodeLine, "&quot", "\"");
        ReplaceSpecialText(decodeLine, "&apos", "'");
        ReplaceSpecialText(decodeLine, "&lt", "<");
        ReplaceSpecialText(decodeLine, "&gt", ">");
        ReplaceSpecialText(decodeLine, "&amp", "&");
        decodeHTML.append(decodeLine).append("\n");
    }
    return decodeHTML;
}

string htmlEn =
    "&ltH1&gtMain title &amp book name&lt/H1&gt\n"
    "&ltp&gt&quotSome&quot text for me &aposIn Apostrofs: `&quot &apos &lt &gt &amp`&lt/p&gt";

int main(int argc, char const* argv[])
{
    cout << HtmlDecode(htmlEn);
    return 0;
}
