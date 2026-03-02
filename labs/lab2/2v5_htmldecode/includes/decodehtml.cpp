#include "decodehtml.hpp"

#include <iostream>
#include <map>

using namespace std;

const map<string, string> ENTITIES = {
    {"&quot;", "\""}, {"&apos;", "'"}, {"&lt;", "<"}, {"&gt;", ">"}, {"&amp;", "&"}};

constexpr int MAX_SIZE_ENTITY = 6;

string GetEntity(const string& html, size_t& i) 
{
    string entity = "&";
    entity.reserve(MAX_SIZE_ENTITY);
    ++i;
    while (i != html.size())
    {
        if (html[i] == '&') break;
        entity += html[i];
        if (html[i] == ';')
        {
            ++i;
            break;
        }
        ++i;
    }
    return entity;
}

void InsertEntity(string& htmlLine, string&& entity)
{
    if (auto it = ENTITIES.find(entity); it != ENTITIES.end())
        htmlLine.append(it->second);
    else
        htmlLine.append(entity);
}

string DecodeHTML(const string& html)
{
    string htmlLine;
    htmlLine.reserve(html.size());

    for (size_t i = 0; i < html.size();)
    {
        if (html[i] == '&')
        {
            InsertEntity(htmlLine, GetEntity(html, i));
            continue;
        }
        htmlLine += html[i];
        ++i;
    }
    return htmlLine;
}
