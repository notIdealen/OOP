//Car
#include <iostream>
#include <sstream>
#include "includes/Car.hpp"

using namespace std;
//
//Все строки ошибок и прочие строки заменить переменными!
//
int main(int argc, char const *argv[])
{
    Car car;
    string line;
    int value = 0;
    
    while (getline(cin, line))
    {
        if (line.empty()) break;
        cout << line << endl;//удалить потом
        stringstream ss(line);
        string action = "";

        ss >> action;
        if (action == "Info")
        {
            auto info = car.Info();
            cout << "> Engine: " << info.isEngineRun << endl;
            cout << "> Direction: " << info.direction << endl;
            cout << "> Speed: " << info.speed << endl;
            cout << "> Gear: " << info.gear << endl;
        }
        else if (action == "EngineOn")
        {
            car.TurnOnEngine();
        }
        else if (action == "EngineOff")
        {
            if (!car.TurnOffEngine())
                cout << "> " << "Car must be stopped and in neutral gear\n";
        }
        else if (action == "SetGear" && ss >> value)
        {
            try
            {
                car.SetGearWithThrow(value);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if (action == "SetSpeed" && ss >> value)
        {
            if (!car.SetSpeed(value))
            {
                if (value < 0)
                {
                    cout << "> " << "Speed cannot be negative\n";
                    continue;
                }
                if (!car.isTurnedOn())
                {
                    cout << "> " << "Cannot set speed while engine is off\n";
                    continue;
                }
                if (car.GetGear() == 0)
                {
                    cout << "> " << "Cannot accelerate on neutral\n";
                    continue;
                }
                cout << "> " << "Speed is out of gear range\n";
            }
        }
        else
            cout << "> " << "Unknown command\n";
    }
    cout << "EXIT\n";
    return 0;
}
//Get-Content actions.txt | .\car.exe
