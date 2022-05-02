/**
 *    @file main.cpp
 *    @brief main file
 *    @author rouxfederico@gmail.com
 */

#include <cassert>
#include <fdm.hpp>
#include <iostream>
#include <ringbuffer.hpp>

#define DATA_TEST 22
#define LEN_TEST 5

using namespace std;

/**
 *   @fn main
 *   @brief main program
 */

int main() {
  cout << "Hello Fluid-Dev!" << endl;

  // ringbuffer<int, LEN_TEST> rb{};

  // for (auto i = 0; i < LEN_TEST; i++) {
  //   assert(!rb.write(DATA_TEST + i));
  // }

  // for (auto rbi : rb) cout << "rbi:" << rbi << endl;

  // auto drb = fdm::diff(rb, 1);

  // for (auto drbi : drb) cout << drbi << endl;

  return 0;
}