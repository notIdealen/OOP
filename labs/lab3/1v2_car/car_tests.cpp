#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "includes/Car.hpp"
#include "includes/CarParameter.hpp"

using namespace std;

struct CarFixture {
    Car car;
    CarFixture() {
        car.TurnOnEngine();
    }
};

void SetCarState(Car& c, int gear, int speed)
{
    c.SetGearWithThrow(gear);
    c.SetSpeed(speed);
}

TEST_CASE("EngineOn/Off")
{
    Car car;
    SECTION("TurnOnEngine")
    {
        REQUIRE(!car.IsTurnedOn());
        REQUIRE(car.TurnOffEngine());
        REQUIRE(car.TurnOnEngine());
        REQUIRE(car.IsTurnedOn());
    }
    SECTION("TurnOffEngine in movement")
    {
        car.TurnOnEngine();
        car.SetGearWithThrow(1);
        REQUIRE(!car.TurnOffEngine());
        car.SetSpeed(20);
        car.SetGearWithThrow(0);
        REQUIRE(!car.TurnOffEngine());
        car.SetSpeed(0);
        REQUIRE(car.TurnOffEngine());
    }
}

TEST_CASE_METHOD(CarFixture, "Get direction")
{
    REQUIRE(car.GetDirection() == CarParameter::noDir);
    SetCarState(car, 1, 20);
    REQUIRE(car.GetDirection() == CarParameter::forwardDir);
    SetCarState(car, 0, 0);
    car.SetGearWithThrow(-1);
    REQUIRE(car.GetDirection() == CarParameter::noDir);
    car.SetSpeed(10);
    REQUIRE(car.GetDirection() == CarParameter::backwardDir);
}

TEST_CASE_METHOD(CarFixture, "Get speed")
{
    REQUIRE(!car.GetSpeed());
    SetCarState(car, 1, 20);
    REQUIRE(car.GetSpeed() == 20);
    SetCarState(car, 1, -10);
    REQUIRE(car.GetSpeed() == 20);
    SetCarState(car, 1, 299);
    REQUIRE(car.GetSpeed() == 20);
    SetCarState(car, 1, 10);
    REQUIRE(car.GetSpeed() == 10);
}

TEST_CASE_METHOD(CarFixture, "Get gear")
{
    REQUIRE(!car.GetGear());
    SetCarState(car, 1, 20);
    REQUIRE(car.GetGear() == 1);
    CHECK_THROWS_WITH(SetCarState(car, 3, 20), "> Unsuitable current speed");
    REQUIRE(car.GetGear() == 1);
    CHECK_THROWS(SetCarState(car, -1, 20));
    REQUIRE(car.GetGear() == 1);
    SetCarState(car, 0, 20);
    REQUIRE(car.GetGear() == 0);
    CHECK_THROWS(SetCarState(car, -1, 20));
    REQUIRE(car.GetGear() == 0);
    car.SetSpeed(0);
    car.SetGearWithThrow(-1);
    REQUIRE(car.GetGear() == -1);
}

TEST_CASE("Gear and Speed limits")
{
    Car car;
    car.TurnOnEngine();

    car.SetGearWithThrow(1);
    REQUIRE(car.SetSpeed(0));
    REQUIRE(car.SetSpeed(30));
    REQUIRE(!car.SetSpeed(31));
    CHECK_THROWS(car.SetGearWithThrow(4));
    car.SetGearWithThrow(2);
    REQUIRE(car.SetSpeed(20));
    REQUIRE(car.SetSpeed(50));
    REQUIRE(!car.SetSpeed(51));
    car.SetGearWithThrow(3);
    REQUIRE(car.SetSpeed(30));
    REQUIRE(car.SetSpeed(60));
    REQUIRE(!car.SetSpeed(61));
    CHECK_THROWS(car.SetGearWithThrow(1));
    car.SetGearWithThrow(4);
    REQUIRE(car.SetSpeed(40));
    REQUIRE(car.SetSpeed(90));
    REQUIRE(!car.SetSpeed(91));
    car.SetGearWithThrow(5);
    REQUIRE(car.SetSpeed(50));
    REQUIRE(car.SetSpeed(150));
    REQUIRE(!car.SetSpeed(151));
    car.SetGearWithThrow(0);
    CHECK_THROWS(car.SetGearWithThrow(-1));
    REQUIRE(car.SetSpeed(0));
    car.SetGearWithThrow(-1);
    REQUIRE(car.SetSpeed(20));
    REQUIRE(car.SetSpeed(0));
    REQUIRE(!car.SetSpeed(21));
    
    // struct GearTest { int gear; int minSpeed; int maxSpeed; };
    // auto testData = GENERATE(
    // GearTest{-1, 20, 0},
    // GearTest{0, 0, 0},
    // GearTest{1, 0, 30},
    // GearTest{2, 20, 50},
    // GearTest{3, 30, 60},
    // GearTest{4, 50, 90},
    // GearTest{5, 60, 150}
    // );
    // car.SetGearWithThrow(testData.gear);
    // REQUIRE(car.SetSpeed(testData.minSpeed));
    // REQUIRE(car.SetSpeed(testData.maxSpeed));
    // CHECK_THROWS(car.SetSpeed(testData.maxSpeed + 5));
}
