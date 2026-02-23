#include <windows.h>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

using dictionary = map<string, vector<string>>;

void WriteDictionary() {}
void ReadDictionary() {}

void PrintTranslation(dictionary& dic, string word)
{
    if (dic.count(word))
    {
        for (size_t i = 0; i < dic[word].size(); i++)
        {
            cout << dic[word][i];
            if (i < dic[word].size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

void OpenDictionary(ifstream& file, string path)
{
    file.open(path);
}

void LoadDictionary(string path, dictionary& dic)
{
    ifstream file(path);
    string word;
    string line;
    stringstream subLine;
    string translation;
    size_t start = 0;
    while (getline(file, line))
    {
        start = line.find('>', start);
        word = line.substr(0, start);
        ++start;
        subLine << line.substr(start);
        while (getline(subLine, translation, ','))
        {
            dic[word].push_back(translation);
        }
        start = 0;
    }
    file.close();
}

void SaveDictionary(string path, dictionary& buf)
{
    ofstream file(path, ios::app);
    string line;
    for (const auto& [k, v] : buf)
    {
        line.append(k).append(">");
        for (const string& s : v)
        {
            line.append(s).append(",");
        }
        line.append("\n");
        file.write(line.c_str(), line.size());
    }
    file.close();
}

void AddWord(dictionary& dic, string word)
{
    string translation;
    getline(cin, translation);
    if (translation == "")
    {
        cout << "Слово " << word << " проигнорировано.\n";
        return;
    }
    dic[word].push_back(translation);
    cout << "Слово '" << word << "' сохранено в словаре как '" << translation << "'.\n";
}

bool FindWord(dictionary& dic, string word)
{
    if (dic.count(word))
    {
        PrintTranslation(dic, word);
        return true;
    }
    return false;
}

string GetWord()
{
    string word;
    do
    {
        getline(cin, word);
        if (word == "") cout << "Введите слово/словосочетание: (для выхода введите '...')\n";
    } while (word == "");
    return word;
}

int main(int argc, char const* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    dictionary dic;
    dictionary tempDic;
    LoadDictionary(argv[1], dic);

    string word, translation;
    cout << "Введите слово/словосочетание: (для выхода введите '...')\n";
    while ((word = GetWord()) != "...")
    {
        if (!FindWord(dic, word) && !FindWord(tempDic, word))
        {
            cout << "Неизвестное слово '" << word
                 << "'. Введите перевод или пустую строку для отказа.\n";
            AddWord(tempDic, word);
        }
    }
    if (!tempDic.empty())
    {
        cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
        cin >> word;
        if (word == "Y" || word == "y")
        {
            SaveDictionary(argv[1], tempDic);
            cout << "Изменения сохранены. До свидания.\n";
        }
        else
            cout << "Изменения не сохранены. До свидания.\n";
    }
    return 0;
}
// g++ dictionary.cpp -o dic.exe
// .\dic.exe dic.txt
// .\dic.exe unexist.txt
