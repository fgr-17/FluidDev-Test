#include <catch2/catch_test_macros.hpp>
#include <ringbuffer.hpp>

TEST_CASE("rb constructor", "[ringbuffer]") {
  ringbuffer<int, 5> rb{};

  int tmp;

  REQUIRE(rb.is_empty());
  REQUIRE(rb.is_full() == false);

  //   REQUIRE(rb.write(22) == 0);
  //   REQUIRE(rb.read(tmp) == 0);
  //   REQUIRE(tmp == 22);
}
