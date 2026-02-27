//crypt
#include <iostream>
#include <fstream>

using namespace std;

constexpr int BUFFER_SIZE = 10;

int StringToInt(const string& key)
{
    constexpr unsigned char MAX_CHAR = 255;
    constexpr char RADIX = 10;
    constexpr char DIGIT_OFFSET = 48;
    int num = 0;
    char digit = '0';
    for (const unsigned char& ch : key)
    {
        if (ch < '0' || ch > '9') throw runtime_error("INVALID VALUE");
        digit = ch - DIGIT_OFFSET;
        if ((MAX_CHAR - digit) / RADIX  >= num) num = num * RADIX + digit;
        else throw runtime_error("INT Overflow");
    }
    return num;
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

void CryptLine(string& line, const string mode, const char key)
{
    if (mode == "crypt")
    {
        for (char& ch : line)
        {
            ch = ch ^ key;
            ch = (ch & 0b1100'0000) >> 3 | (ch & 0b0001'1100) >> 2 | (ch & 0b0010'0000) << 2 | (ch & 0b0000'0011) << 5;
        }
        return;
    }
    if (mode == "decrypt")
    {
        for (char& ch : line)
        {
            ch = (ch << 3) & 0b1100'0000 | (ch << 2) & 0b0001'1100 | (ch >> 2) & 0b0010'0000 | (ch >> 5) & 0b0000'0011;
            ch = ch ^ key;
        }
        return;
    }
    throw runtime_error("INVALID MODE");
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
            
            const unsigned char key = StringToInt(argv[4]);
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
//.\crypt.exe crypt data/text.bin data/en.bin 93
//.\crypt.exe decrypt data/en.bin data/de.bin 93
