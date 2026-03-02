//crypt
#include <iostream>
#include <fstream>

using namespace std;

constexpr int BUFFER_SIZE = 4096;

void IsValidKey(int key)
{
    if (key < 0 || 255 < key) throw runtime_error("INVALID KEY");
}

void OpenFileForRead(ifstream& file, string path)
{
    file.open(path, std::ios::binary);
    if (!file) throw std::runtime_error("INVALID PATH: " + path);
}

void OpenFileForWrite(ofstream& file, string path)
{
    file.open(path, std::ios::binary);
    if (!file) throw std::runtime_error("INVALID PATH: " + path);
}

bool ReadLine(ifstream& from, string& line, char* buf)
{
    line.clear();
    if (from.read(buf, sizeof(buf)) || from.gcount() > 0)
    {
        line.append(buf, static_cast<size_t>(from.gcount()));
        return true;
    }
    return false;
}

void EncryptLine(string& line, const char key)
{
    for (char& ch : line)
    {
        ch = ch ^ key;
        ch = (ch & 0b1100'0000) >> 3 | (ch & 0b0001'1100) >> 2 | (ch & 0b0010'0000) << 2 | (ch & 0b0000'0011) << 5;
    }
}

void DecryptLine(string& line, const char key)
{
    for (char& ch : line)
    {
        ch = (ch << 3) & 0b1100'0000 | (ch << 2) & 0b0001'1100 | (ch >> 2) & 0b0010'0000 | (ch >> 5) & 0b0000'0011;
        ch = ch ^ key;
    }
}

void CryptLine(string& line, const string mode, const char key)
{
    if (mode == "crypt") EncryptLine(line, key);
    else if (mode == "decrypt") DecryptLine(line, key);
    else throw runtime_error("INVALID MODE");
}

int main(int argc, char const *argv[])
{
    if (argc == 5) 
    {
        ifstream from;
        ofstream to;
        try
        {
            OpenFileForRead(from, argv[2]);
            OpenFileForWrite(to, argv[3]);

            string line;
            line.reserve(BUFFER_SIZE);
            char buf[BUFFER_SIZE];
            const int key = stoi(argv[4]);
            IsValidKey(key);
            while (ReadLine(from, line, buf))
            {
                CryptLine(line, argv[1], key);
                to.write(line.c_str(), line.size());
            }
            to.close();
            if (!from.eof()) throw std::runtime_error("INVALID READING");
            from.close();
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
        }
    }
    else
    {
        cerr << "INVALID argc number\n";
        return 1;
    }
    return 0;
}
//g++ crypt.cpp -o crypt.exe
//.\crypt.exe crypt data/kniga.txt data/en.bin 93
//.\crypt.exe decrypt data/en.bin data/de.bin 93
