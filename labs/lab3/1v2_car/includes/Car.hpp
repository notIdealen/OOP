#pragma once

#include <string>
#include "CarParameter.hpp"

struct CarInfo
{
    int speed;
    int gear;
    std::string isEngineRun;
    std::string direction;
};

using MyException = std::pair<bool, std::string>;

class Car
{
public:
    bool IsTurnedOn();
    bool TurnOnEngine();
    bool TurnOffEngine();
    std::string GetDirection() const;
    int GetSpeed() const;
    int GetGear() const;
    void SetGearWithThrow(int gear);
    bool SetSpeed(int speed);
    CarInfo Info();
private:
    int m_speed = 0;
    int m_gear = 0;
    bool m_isEngineRun = false;

    bool IsSpeedAndGearConsistent(int gear, int speed) const;
};
