#include <iostream>
#include <map>

using namespace std;
// Что с названием???
string HtmlDecode(const string& html)
{
    string htmlLine;
    htmlLine.reserve(html.size());

    const map<string, string> templates = {
        {"&quot", "\""}, {"&apos", "'"}, {"&lt", "<"}, {"&gt", ">"}, {"&amp", "&"}};

    bool matchFound = false;

    for (size_t i = 0; i < html.size();)
    {
        if (html[i] == '&')
        {
            for (const auto& [k, v] : templates)
            {
                if (html.substr(i, k.size()) == k)
                {
                    matchFound = true;
                    htmlLine.append(v);
                    i = i + k.size() - 1;// сделал так чтобы уменьшить кол-во строк на 5
                    break;
                }
                matchFound = false;
            }
            if (!matchFound) htmlLine += html[i];// можно убрать else, оставить только этот иф
        }
        else htmlLine += html[i];
        ++i;
    }
    return htmlLine;
}

int main(int argc, char const* argv[])
{
    string htmlDecodeLine;
    string line;
    while (getline(cin, line))
    {
        if (line == "") break;
        htmlDecodeLine.append(HtmlDecode(line)).append("\n");
    }
    cout << "----------------------------------------------------\n";
    cout << htmlDecodeLine << endl;
    return 0;
}
// g++ htmlDecode.cpp -o decode.exe
// .\decode.exe data/in.txt > data/out.txt
// Get-Content data/in.txt | .\decode.exe
