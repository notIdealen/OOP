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
        REQUIRE(!car.isTurnedOn());
        REQUIRE(car.TurnOffEngine());
        REQUIRE(car.TurnOnEngine());
        REQUIRE(car.isTurnedOn());
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

TEST_CASE("Set speed")
{

}

TEST_CASE("Set gear")
{

}

TEST_CASE("Info")
{

}
