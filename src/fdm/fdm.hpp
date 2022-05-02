/**
 * @file finite_diff.hpp
 * @brief namespace used for calculating finite difference method
 * @author Federico Roux (rouxfederico@gmail.com)
 */

#include <memory>
#include <stdexcept>
#include <vector>

namespace fdm {

/**
 * @fn diff
 * @brief class T must be an iterator
 */

template <class T>
std::vector<float> diff(T& buf, float dx) {
  if (buf.size() < 2) throw std::length_error("buf length must be > 2");
  if (dx == 0) throw std::invalid_argument("dx cant be zero");

  //   std::unique_ptr<std::vector<float>> dbuf(
  //       new std::vector<float>[buf.size() - 1]);

  std::vector<float> dbuf;

  dbuf.reserve(buf.size() - 1);
  bool first = true;

  for (auto e : buf) {
    decltype(e) e_1;
    if (first) {
      first = false;
    } else {
      dbuf.push_back((e - e_1) / dx);
    }
    e_1 = e;
  }

  return dbuf;
}
}  // namespace fdm