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

void help()
{
    cout << "OPISANIE DESCRIPTION.\n";
}

void openFile(fstream& file, OpenMode mode, string& path)
{
    if (mode == OpenMode::input) file.open(path, ios::in);
    if (mode == OpenMode::output) file.open(path, ios::out);
    if (!file.is_open()) throw runtime_error("ERROR");
}

void replaceSubstring(const string& pattern, const string& filler, string& token)
{
    size_t pos = 0;
    if (filler.length() > pattern.length())
        token.reserve(ceil(token.length() * filler.length() / pattern.length()) + 1);
    if (pattern != "")
        while ((pos = token.find(pattern, pos)) != string::npos)
        {
            token.replace(pos, pattern.length(), filler);
            pos += filler.length();
        }
}

void writeFile(istream& fromF, fstream& toF, string& pattern, string& filler)
{
    string text;
    while (getline(fromF, text)) 
    {
        if (text.empty()) break;
        replaceSubstring(pattern, filler, text);
        toF << text;
        toF << '\n';
    }
}

int main(int argc, char const *argv[])
{
    auto start = chrono::high_resolution_clock::now();
    if (argc == 2)
    {
        if (static_cast<string>(argv[1]) == "-h") help();
        return 0;
    }

    fstream outF;
    string outFPath;
    string pattern = "";
    string filler = "";

    if (argc == 1)
    {
        outFPath = "./data/out.txt";
        try 
        { 
            openFile(outF, OpenMode::output, outFPath); 
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
            return 0;
        }

        cout << "Input pattern:";
        cin >> pattern;
        cout << "Input new value:";
        cin >> filler;
        cout << "Input text:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        writeFile(cin, outF, pattern, filler);

        outF.close();
        return 0;
    }

    if (argc > 2)
    {
        fstream inF;
        string inFPath  = argv[1];
               outFPath = argv[2];
        try 
        { 
            openFile(inF, OpenMode::input, inFPath); 
            openFile(outF, OpenMode::output, outFPath);
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
            return 1;
        }

        if (argc > 3) pattern = argv[3];
        if (argc > 4) filler = argv[4];
        
        writeFile(inF, outF, pattern, filler); 
        inF.close();
        outF.close();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}
//./r.exe ./data/in.txt ./data/out.txt qw QW
