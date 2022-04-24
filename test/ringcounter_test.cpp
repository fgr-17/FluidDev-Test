#include <catch2/catch_test_macros.hpp>
#include <ringcounter.hpp>

TEST_CASE("rc constructor", "[ring_counter]") {
  ringcounter rc{5};

  REQUIRE(rc.len() == 5);

  rc = 3;
  REQUIRE(rc == 3);

  rc++;
  REQUIRE(rc == 4);

  rc++;
  REQUIRE(rc == 0);

  rc--;
  REQUIRE(rc == 4);

  rc--;
  REQUIRE(rc == 3);
  REQUIRE(rc + 1 == 4);
}
