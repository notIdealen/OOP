#include <windows.h>

#include "includes/translation.hpp"

using namespace std;

int main(int argc, char const* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    MultiDictionary dic;
    MultiDictionary tempDic;
    LoadDictionary(argv[1], dic);

    string word;
    do
    {
        cout << "Введите слово/словосочетание: (для выхода введите '...')\n";
        word = GetWord();
        if (word == "" || word == "...") continue;
        
        if (dic.count(word))
            PrintTranslation(dic, word);
        else if (tempDic.count(word))
            PrintTranslation(tempDic, word);
        else
        {
            cout << "Неизвестное слово '" << word
                 << "'. Введите перевод или пустую строку для отказа.\n";
            if (const string translation = SaveWord(tempDic, word); translation != "")
                cout << "Слово '" << word << "' сохранено в словаре как '" << translation << "'.\n";
            else
                cout << "Слово " << word << " проигнорировано.\n";
        }
    }
    while (word != "...");
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
// g++ dictionary.cpp includes/bitranslation.cpp -o dic.exe
// .\dic.exe dic.txt
// .\dic.exe unexist.txt
