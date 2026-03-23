#pragma once

#include <string>

namespace CarParameter
{
    inline constexpr int minSpeed = 0;
    inline constexpr int maxSpeed = 150;

    inline constexpr int minReverseGearSpeed = 0;
    inline constexpr int maxReverseGearSpeed = 20;
    inline constexpr int minFirstGearSpeed = 0;
    inline constexpr int maxFirstGearSpeed = 30;
    inline constexpr int minSecondGearSpeed = 20;
    inline constexpr int maxSecondGearSpeed = 50;
    inline constexpr int minThirdGearSpeed = 30;
    inline constexpr int maxThirdGearSpeed = 60;
    inline constexpr int minFourthGearSpeed = 40;
    inline constexpr int maxFourthGearSpeed = 90;
    inline constexpr int minFifthGearSpeed = 50;
    inline constexpr int maxFifthGearSpeed = 150;

    inline constexpr int reverseGear = -1;
    inline constexpr int neutralGear = 0;
    inline constexpr int firstGear = 1;
    inline constexpr int secondGear = 2;
    inline constexpr int thirdGear = 3;
    inline constexpr int fourthGear = 4;
    inline constexpr int fifthGear = 5;
    inline constexpr int minGear = reverseGear;
    inline constexpr int maxGear = fifthGear;

    inline const std::string forwardDir = "forward";
    inline const std::string backwardDir = "backward";
    inline const std::string noDir = "standing still";
};
