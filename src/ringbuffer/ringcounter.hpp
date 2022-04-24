/**
 * @file ringcounter.hpp
 * @brief class defined to control circular counter and its operators
 * @author Federico Roux (rouxfederico@gmail.com)
 */

class ringcounter {
 public:
  explicit ringcounter(unsigned int len) : _c(0), _len(len) {}
  ~ringcounter() {}

  unsigned int len(void) const { return _len; }

  unsigned int operator++(int) {
    inc();
    return get();
  }

  unsigned int operator--(int) {
    dec();
    return get();
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
  void set(const unsigned int c) { _c = c % _len; }

  void inc(void) { _c = (_c + 1) % _len; }
  void dec(void) { (_c == 0) ? (_c = _len - 1) : _c--; }

  bool is_equal(const unsigned int& x) const { return (get() == x); }
  unsigned int _c;
  const unsigned int _len;
};
