#include <iostream>
#include <map>

using namespace std;

const map<string, string> templates = {
    {"&quot", "\""}, {"&apos", "'"}, {"&lt", "<"}, {"&gt", ">"}, {"&amp", "&"}};
//на подфункции
// сущ заканчиваются ;
string DecodeHTML(const string& html)
{
    string htmlLine;
    htmlLine.reserve(html.size());
    bool matchFound = false;

    for (size_t i = 0; i < html.size();)
    {
        if (html[i] == '&')
        {
            for (const auto& [key, value] : templates)
            {
                if (html.substr(i, key.size()) == key)
                {
                    matchFound = true;
                    htmlLine.append(value);
                    i = i + key.size() - 1;// сделал так чтобы уменьшить кол-во строк на 5, уберу -1
                    break;
                }
                matchFound = false;
            }
            if (!matchFound) htmlLine += html[i];// можно убрать else, оставить только этот иф
        }
        else
            htmlLine += html[i];
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
        htmlDecodeLine.append(DecodeHTML(line)).append("\n");
    }
    cout << "----------------------------------------------------\n";
    cout << htmlDecodeLine << endl;
    return 0;
}
// g++ htmlDecode.cpp -o decode.exe
// .\decode.exe data/in.txt > data/out.txt
// Get-Content data/in.txt | .\decode.exe
