#include <memory>
#include <mutex>
#include <ringcounter.hpp>

using namespace std;

template <class T, unsigned int L>

class ringbuffer {
 public:
  explicit ringbuffer() : _rb(new T[L]), _len(L), _head(L - 1), _tail(0) {}
  ~ringbuffer() {}

  bool is_full(void) const {}

  bool is_empty(void) const { return true; }

 private:
  unique_ptr<T> _rb;
  mutex _m;

  ringcounter _head{L};
  ringcounter _tail{L};

  const unsigned int _len;
};