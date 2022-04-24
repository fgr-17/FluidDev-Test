#include <catch2/catch_test_macros.hpp>
#include <ringbuffer.hpp>

TEST_CASE("rb constructor", "[basic]") {
  ringbuffer<int, 5> rb1();

  REQUIRE(1 == 1);
}
