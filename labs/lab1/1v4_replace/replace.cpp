//g++ replace.cpp -o r.exe
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;

enum class OpenMode { input, output };

void Help()
{
    cout << "OPISANIE DESCRIPTION.\n";
}

// подавать отдельно ин и оут
void OpenFile(fstream& file, OpenMode mode, string& path)
{
    if (mode == OpenMode::input) file.open(path, ios::in);
    if (mode == OpenMode::output) file.open(path, ios::out);
    if (!file.is_open()) throw runtime_error("ERROR");
}

void ReplaceSubstring(const string& pattern, const string& filler, string& token)
{
    size_t pos = 0;
    // изменить способ уменьщ=шения колва релокаций? хрупко 
    // if (filler.length() > pattern.length())
    //     token.reserve(ceil(token.length() * filler.length() / pattern.length()) + 1);
    if (pattern != "")
        while ((pos = token.find(pattern, pos)) != string::npos)
        {
            token.replace(pos, pattern.length(), filler);
            pos += filler.length();
        }
}
// заменить fstream на ostream, изменить названия параметров
// одной фн открываю и на чтение и на запись поэтому использую fstream
void WriteFile(istream& fromF, fstream& toF, string& pattern, string& filler)
{
    string text;
    while (getline(fromF, text)) 
    {
        if (text.empty()) break;
        ReplaceSubstring(pattern, filler, text);
        toF << text;
        toF << '\n';
    }
}

void UseModeWithOneArg(fstream& outF)
{
    string outFPath = "./data/out.txt";
    string pattern = "";
    string filler = "";
    try 
    { 
        OpenFile(outF, OpenMode::output, outFPath); 
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }

    cout << "Input pattern:";
    cin >> pattern;
    cout << "Input new value:";
    cin >> filler;
    cout << "Input text:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    WriteFile(cin, outF, pattern, filler);

    outF.close();
}

void UseModeMoreThanThreeArgs(fstream& outF, string inFPath, string outFPath)
{
    fstream inF;
    // string inFPath  = argv[1];
    // outFPath = argv[2];
    try 
    { 
        OpenFile(inF, OpenMode::input, inFPath); 
        OpenFile(outF, OpenMode::output, outFPath);
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
        return 1;
    }

    if (argc > 3) pattern = argv[3];
    if (argc > 4) filler = argv[4];
    
    WriteFile(inF, outF, pattern, filler); 
    inF.close();
    outF.close();
}

int main(int argc, char const *argv[])
{
    fstream outF;
    string outFPath;
    string pattern = "";
    string filler = "";

    auto start = chrono::high_resolution_clock::now();
    switch (argc)
    {
    case 1:
        UseModeWithOneArg(outF);   
        break;
    case 2:
        Help();
        break;
    case 3:
    case 4:
    case 5:
        UseModeMoreThanThreeArgs(outF, argv[1], argv[2], argv[3], argv[4]);
        break;

    }
    // if (argc == 2)
    // {
    //     if (static_cast<string>(argv[1]) == "-h") Help();
    //     return 0;
    // }

    // if (argc == 1)
    // {
    //     outFPath = "./data/out.txt";
    //     try 
    //     { 
    //         OpenFile(outF, OpenMode::output, outFPath); 
    //     }
    //     catch(const std::exception& e)
    //     {
    //         cout << e.what() << endl;
    //         return 0;
    //     }

    //     cout << "Input pattern:";
    //     cin >> pattern;
    //     cout << "Input new value:";
    //     cin >> filler;
    //     cout << "Input text:\n";
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     WriteFile(cin, outF, pattern, filler);

    //     outF.close();
    //     return 0;
    // }

    // if (argc > 2)
    // {
    //     fstream inF;
    //     string inFPath  = argv[1];
    //            outFPath = argv[2];
    //     try 
    //     { 
    //         OpenFile(inF, OpenMode::input, inFPath); 
    //         OpenFile(outF, OpenMode::output, outFPath);
    //     }
    //     catch(const std::exception& e)
    //     {
    //         cout << e.what() << endl;
    //         return 1;
    //     }

    //     if (argc > 3) pattern = argv[3];
    //     if (argc > 4) filler = argv[4];
        
    //     WriteFile(inF, outF, pattern, filler); 
    //     inF.close();
    //     outF.close();
    // }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}
//./r.exe ./data/in.txt ./data/out.txt qw QW
