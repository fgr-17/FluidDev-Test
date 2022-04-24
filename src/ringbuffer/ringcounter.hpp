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
  void set(const unsigned int c) { _c = c % _len; }

 private:
  void inc(void) { _c = (_c + 1) % _len; }
  void dec(void) { (_c == 0) ? (_c = _len - 1) : _c--; }

  unsigned int _c;
  const unsigned int _len;
};
