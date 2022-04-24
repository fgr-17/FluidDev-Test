#include <memory>
#include <mutex>
#include <ringcounter.hpp>

using namespace std;

template <class T, unsigned int L>

class ringbuffer {
 public:
  explicit ringbuffer() : _rb(new T[L]), _len(L) {}
  ~ringbuffer() {}

  int init(void) { return 0; }

  bool is_full(void) const { return true; }

  bool is_empty(void) const { return true; }

 private:
  unique_ptr<T> _rb;
  mutex _m;

  ringcounter _head{L};
  ringcounter _tail{L};

  const unsigned int _len;
};