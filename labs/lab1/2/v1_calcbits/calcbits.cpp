//Вариант №1 – calcbits – 20 баллов
//g++ calcbits.cpp -o cb.exe
#include <iostream>

using namespace std;

void help()
{
    cout << "Program calculate number of one-bits in byte.\n";
}

bool isInvalidByte(int byte)
{
    if (byte < 0 || byte > 255) 
    {
        cout << "Invalid argument" << endl;
        return true;
    }  
    return false;
}

int main(int argc, char const *argv[])
{
    if (argc > 2) 
    {
        cout << "Invalid argument" << endl;
        return 1;
    }

    int byte;
    if (argc == 1) 
    {
        cin >> byte;
        if (isInvalidByte(byte)) return 1;
    }

    if (argc == 2)
    {
        if (static_cast<string>(argv[1]) == "-h")
        {
            help();
            return 0;
        }
        byte = atoi(argv[1]);
        if (isInvalidByte(byte)) return 1;
    }

    int counter = 0;
    for (byte; byte != 0; byte >>= 1)
    {
        if (byte & 1 == 1) ++counter;  
    }
    cout << "Number of one-bits: " << counter << endl;
    return 0;
}

