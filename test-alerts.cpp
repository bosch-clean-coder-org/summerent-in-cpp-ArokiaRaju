#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits 1") {
  REQUIRE(inferBreach(30, 20, 10) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits 2") {
  REQUIRE(inferBreach(15, 12, 32) == NORMAL);
}

TEST_CASE("classifyTemperature breach according to limits 1") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW); //inferBreach(-1, 0, 35)
}

TEST_CASE("classifyTemperature breach according to limits 2") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH); //inferBreach(50, 0, 45)
}

TEST_CASE("classifyTemperature breach according to limits 3") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL); //inferBreach(30, 0, 40)
}

TEST_CASE("checkAndAlert 1") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,-1) == TOO_LOW); //inferBreach(-1, 0, 35)
}
