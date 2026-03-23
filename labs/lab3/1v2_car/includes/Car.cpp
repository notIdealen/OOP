#include "Car.hpp"
#include <stdexcept>

#include <iostream>

using namespace CarParameter;

Car::Car(/* args */)
{
}

Car::~Car()
{
}

bool Car::isTurnedOn()
{
    return m_isEngineRun;
}

std::string Car::GetDirection() const
{
    if (m_speed < 0)
        return backwardDir;
    if (m_speed == 0)
        return noDir;
    return forwardDir;
}

int Car::GetSpeed() const
{
    return abs(m_speed);
}

int Car::GetGear() const
{
    return m_gear;
}

bool Car::TurnOnEngine()
{
    return m_isEngineRun = true;
};

bool Car::TurnOffEngine()
{
    if (m_speed == 0 && m_gear == 0)
    {
        m_isEngineRun = false;
        return true;
    }
    return false;
}

CarInfo Car::Info()
{
    return {
        speed : abs(m_speed),
        gear : m_gear,
        isEngineRun : m_isEngineRun ? "on" : "off",
        direction : GetDirection()
    };
}

bool Car::IsSpeedAndGearConsistent(int gear, int speed) const
{
    if (gear == reverseGear && 
            minReverseGearSpeed <= speed && speed <= maxReverseGearSpeed && m_speed <= 0 ||
        gear == neutralGear && speed <= abs(m_speed) ||
        gear == firstGear && 
            minFirstGearSpeed <= speed && speed <= maxFirstGearSpeed && m_speed >= 0||
        gear == secondGear &&
            minSecondGearSpeed <= speed && speed <= maxSecondGearSpeed ||
        gear == thirdGear &&
            minThirdGearSpeed <= speed && speed <= maxThirdGearSpeed ||
        gear == fourthGear &&
            minFourthGearSpeed <= speed && speed <= maxFourthGearSpeed ||
        gear == fifthGear &&
            minFifthGearSpeed <= speed && speed <= maxFifthGearSpeed)
    {
        return true;
    }
    return false;
}

// bool Car::SetGear(int gear)
// {
//     if (m_isEngineRun && CarParameter::minGear <= gear && gear <= CarParameter::maxGear)
//     {
//         if (IsSpeedAndGearConsistent(gear, m_speed))
//         {
//             m_gear = gear;
//             return true;
//         }
//     }
//     return false;
// };

void Car::SetGearWithThrow(int gear)
{
    if (!m_isEngineRun)
        throw std::invalid_argument("> Cannot set gear while engine is off");
    if (CarParameter::minGear > gear || gear > CarParameter::maxGear)
        throw std::out_of_range("> Invalid gear");
    if (m_speed != 0 && (m_gear >= 0 && gear < 0 || m_gear <= 0 && gear > 0))
        throw std::invalid_argument("> Cannot reverse while moving");
    if (IsSpeedAndGearConsistent(gear, m_speed))
    {
        m_gear = gear;
        return;
    }
    throw std::invalid_argument("> Unsuitable current speed");
};

bool Car::SetSpeed(int speed)
{
    if (m_isEngineRun)
    {
        if (IsSpeedAndGearConsistent(m_gear, speed))
        {
            if (m_speed < 0 || m_gear < 0)
                m_speed = -speed;
            else
                m_speed = speed;
            return true;
        }
    }
    return false;
};
