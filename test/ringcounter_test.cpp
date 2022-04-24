#include <catch2/catch_test_macros.hpp>
#include <ringcounter.hpp>

TEST_CASE("rc constructor", "[ring_counter]") {
  ringcounter rc{5};

  REQUIRE(rc.len() == 5);

  rc = 3;
  REQUIRE(rc.get() == 3);

  rc++;
  REQUIRE(rc.get() == 4);

  rc++;
  REQUIRE(rc.get() == 0);

  rc--;
  REQUIRE(rc.get() == 4);

  rc--;
  REQUIRE(rc.get() == 3);
}
