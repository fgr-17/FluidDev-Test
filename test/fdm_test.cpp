#include <catch2/catch_test_macros.hpp>
#include <fdm.hpp>
#include <ringbuffer.hpp>

#define DATA_TEST 22
#define LEN_TEST 5

TEST_CASE("diff method", "[fdm]") {
  ringbuffer<int, LEN_TEST> rb{};

  REQUIRE(rb.write(DATA_TEST + 1) == 0);
  REQUIRE(rb.write(DATA_TEST + 2) == 0);
  REQUIRE(rb.write(DATA_TEST + 3) == 0);
  REQUIRE(rb.write(DATA_TEST + 4) == 0);
  REQUIRE(rb.write(DATA_TEST + 5) != 0);

  //   auto drb = fdm::diff(rb, 1);

  //   for (auto drbi : drb) cout << drbi << endl;
}
