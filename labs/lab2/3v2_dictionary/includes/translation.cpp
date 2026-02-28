#include "translation.hpp"
#include <sstream>
#include <fstream>

using namespace std;

std::string GetWord()
{
    std::string word;
    getline(cin, word);
    for (char& ch : word) ch = tolower(ch);
    return word;
}

void PrintTranslation(Dictionary& dic, string word)
{
    for (auto it = dic[word].begin(); true;)
    {
        if (it == dic[word].end()) break;
        cout << *it;
        it++;
        if (it != dic[word].end()) cout << ", ";
    }
    cout << endl;
}

void TrimSpace(string& s)
{
    size_t start = s.find_first_not_of(' ');
    size_t end = s.find_last_not_of(' ');
    s = s.substr(start, end - start + 1);
}

string SaveWord(Dictionary& dic, string word)
{
    string translations, translation;
    getline(cin, translations);
    if (translations == "") return "";

    stringstream ss(translations);
    while (getline(ss, translation, ','))
    {
        TrimSpace(translation);
        dic[word].push_back(translation);
    }
    return translations;
}

void SaveDictionary(string path, Dictionary& dic)
{
    ofstream file(path, ios::app);
    if (!file.is_open()) throw runtime_error("INVALID output file path: " + path);

    string line;
    for (const auto& [key, words] : dic)
    {
        line.append(key).append(">");
        for (const string& word : words)
        {
            line.append(word).append(",");
        }
        line.append("\n");
        file.write(line.c_str(), line.size());
    }
    file.close();
}

void LoadDictionary(string path, Dictionary& dic)
{
    ifstream file(path);
    if (!file.is_open()) throw runtime_error("INVALID dictionary path: " + path);

    string line, word, translation;
    size_t start = 0;
    while (getline(file, line))
    {
        start = line.find('>', start);
        word = line.substr(0, start);
        ++start;
        stringstream subLine(line.substr(start));
        while (getline(subLine, translation, ','))
        {
            dic[word].push_back(translation);
        }
        start = 0;
    }
    if (!file.eof()) throw runtime_error("INVALID reading: LoadDictionary");
    file.close();
}

