/**
 * @file ringcounter.hpp
 * @brief class defined to control circular counter and its operators
 * @author Federico Roux (rouxfederico@gmail.com)
 */

#include <iostream>

class ringcounter {
 public:
  explicit ringcounter(unsigned int l, unsigned int c = 0) : _c(c), _len(l) {}
  ~ringcounter() {}

  unsigned int len(void) const { return _len; }

  unsigned int operator++() {
    inc();
    return get();
  }

  unsigned int operator++(int) {
    auto tmp = get();
    inc();
    return tmp;
  }

  unsigned int operator--() {
    dec();
    return get();
  }

  unsigned int operator--(int) {
    auto tmp = get();
    dec();
    return tmp;
  }

  void operator=(int x) { set(x); }

  unsigned int get(void) const { return _c; }

  unsigned int operator+(const unsigned int x) const {
    return (get() + x) % _len;
  }

  bool operator==(const unsigned int& x) const { return is_equal(x); }
  bool operator==(const ringcounter& x) const {
    return (is_equal(x.get()) && (len() == x.len()));
  }

 private:
  void set(const unsigned int c) {
    if (_len == 0) return;
    _c = c % _len;
  }

  void inc(void) {
    if (_len == 0) return;
    _c = (_c + 1) % _len;
  }
  void dec(void) { (_c == 0) ? (_c = _len - 1) : _c--; }

  bool is_equal(const unsigned int& x) const { return (get() == x); }
  unsigned int _c;
  const unsigned int _len;
};
