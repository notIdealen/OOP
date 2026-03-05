#include "translation.hpp"
#include <sstream>
#include <fstream>

using namespace std;

void TrimSpace(string& s)
{
    size_t start = s.find_first_not_of(' ');
    size_t end = s.find_last_not_of(' ');
    s = s.substr(start, end - start + 1);
}

std::string GetWord()
{
    std::string word;
    getline(cin, word);
    if (!word.empty()) TrimSpace(word);
    for (char& ch : word) ch = tolower(ch);
    return word;
}
//
void PrintTranslation(MultiDictionary& dic, string word)
{
    auto range = dic.equal_range(word);
    
    for (auto it = range.first; it != range.second;) {
        cout << it->second;
        ++it;
        if (it != range.second) cout << ", ";
    }
    cout << endl;
}

string SaveWord(MultiDictionary& dic, string word)
{
    string translations, translation;
    getline(cin, translations);
    if (translations == "") return "";

    stringstream ss(translations);
    while (getline(ss, translation, ','))
    {
        TrimSpace(translation);
        dic.emplace(word, translation);
        dic.emplace(translation, word);
    }
    return translations;
}

void SaveDictionary(string path, MultiDictionary& dic)
{
    ofstream file(path, ios::app);
    if (!file.is_open()) throw runtime_error("INVALID output file path: " + path);

    string line;
    for (const auto& [key, word] : dic)
    {
        line.append(key).append(">").append(word).append("\n");
        file.write(line.c_str(), line.size());
        line.clear();
    }
    file.close();
}

void LoadDictionary(string path, MultiDictionary& dic)
{
    ifstream file(path);
    if (!file.is_open()) throw runtime_error("INVALID dictionary path: " + path);

    string line, word;
    size_t start = 0;
    while (getline(file, line))
    {
        start = line.find('>', start);
        word = line.substr(0, start);
        ++start;
        dic.emplace(word, line.substr(start));
        start = 0;
    }
    if (!file.eof()) throw runtime_error("INVALID reading: LoadDictionary");
    file.close();
}
