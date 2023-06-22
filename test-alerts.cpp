#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits 1111") {
  REQUIRE(inferBreach(30, 20, 10) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits 2222") {
  REQUIRE(inferBreach(15, 12, 32) == NORMAL);
}
