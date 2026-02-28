//Вариант №5 – flipbyte – 50 баллов
//g++ flipbyte.cpp -o fb.exe
#include <iostream>

using namespace std;

void help()
{
    cout << "Program reverse bits in byte.\n";
}

bool isInvalidInput(int num)
{
    if (num < 0 || num > 255) 
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

    int num;
    if (argc == 1) 
    {
        cin >> num;
        if (isInvalidInput(num)) return 1;
    }

    if (argc == 2)
    {
        if (static_cast<string>(argv[1]) == "-h")
        {
            help();
            return 0;
        }
        num = atoi(argv[1]);
        if (isInvalidInput(num)) return 1;
    }

    int invertNum = 0;
    for (int i = 7; 0 <= i; --i)
    {
        invertNum |= num & 1;
        num >>= 1;
        if (i) invertNum <<= 1;
    }

    cout << "Reverse number: " << invertNum << endl;
    return 0;
}

