#include <catch2/catch_test_macros.hpp>
#include <ringbuffer.hpp>

#define DATA_TEST 22
#define LEN_TEST 5

TEST_CASE("rb sliding", "[ringbuffer]") {
  ringbuffer<int, LEN_TEST> rb{};

  int tmp;

  SECTION("Checking initialization:") {
    REQUIRE(rb.is_empty());
    REQUIRE(rb.is_full() == false);
    REQUIRE(rb.size() == LEN_TEST);
  }

  SECTION("Read and writing:") {
    REQUIRE(rb.write(DATA_TEST) == 0);
    REQUIRE(rb.read(tmp) == 0);
    REQUIRE(tmp == DATA_TEST);
  }

  SECTION("Filling and reading the entire buffer:") {
    for (auto i = 0; i < LEN_TEST; i++) {
      REQUIRE(rb.write(DATA_TEST + i) == 0);
    }
    REQUIRE(rb.write(DATA_TEST + 6) != 0);  // ringbuffer should be full

    for (auto i = 0; i < LEN_TEST; i++) {
      REQUIRE(rb.read(tmp) == 0);
      REQUIRE(tmp == DATA_TEST + i);
    }
    REQUIRE(rb.read(tmp) != 0);  // ringbuffer should be empty
  }
}

TEST_CASE("rb iterator", "[ringbuffer]") {
  ringbuffer<int, LEN_TEST> rb{};

  int i = 0;

  REQUIRE(rb.write(DATA_TEST + 1) == 0);
  REQUIRE(rb.write(DATA_TEST + 2) == 0);
  REQUIRE(rb.write(DATA_TEST + 3) == 0);
  REQUIRE(rb.write(DATA_TEST + 4) == 0);
  REQUIRE(rb.write(DATA_TEST + 5) != 0);

  for (auto rbi : rb) {
    REQUIRE(rbi == DATA_TEST + ++i);
  }
}