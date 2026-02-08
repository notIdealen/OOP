//Вариант №2 – rotatebyte – 30 баллов
//g++ rotatebyte.cpp -o rb.exe
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = (argc == 4) ? atoi(argv[1]) : 0;
    int shift = (argc == 4) ? atoi(argv[2]) : 0; 
    char dir = argv[3][0]; 

    int buf;
    const int BYTE_SIZE = 8;
    switch (dir)
    {
        case 'L':
            buf = (num >> (BYTE_SIZE - shift % BYTE_SIZE));
            num = buf | ((num << shift % BYTE_SIZE) & 0b1111'1111);
            break;
        case 'R':
            buf = (num << (BYTE_SIZE - shift % BYTE_SIZE)) & 0b1111'1111;
            num = buf | (num >> shift % BYTE_SIZE);
            break;
        default: 
            cout << "Wrong dir" << endl;
    }
    

    // int final = buf | num;

    cout << num << endl;

    // uint8_t ui = 214 + 50;
    // cout << (int)ui << endl;
    // ui <<= 1;
    // cout << (int)ui << endl;

    // for (int i = 0; i < 8; i++) cout << (ui <<= 1) << endl;

    return 0;
}
