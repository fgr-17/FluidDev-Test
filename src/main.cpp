/**
 *    @file main.cpp
 *    @brief main file
 *    @author rouxfederico@gmail.com
 */

#include <iostream>
#include <ringbuffer.hpp>

using namespace std;

/**
 *   @fn main
 *   @brief main program
 */

int main(int argc, char *argv[]) {
  ringbuffer<int, 5> rb{};

  if (rb.is_empty()) cout << "Ringbuffer is empty" << endl;

  if (!rb.is_full()) cout << "Ringbuffer is not full" << endl;

  if (!rb.write(21)) cout << "Data written correctly" << endl;

  cout << "Hello Fluid-Dev!" << endl;

  return 0;
}