/**
 * @file ringbuffer.hpp
 * @brief class defined to control circular buffers and its operators
 * @author Federico Roux (rouxfederico@gmail.com)
 */

#include <memory>
#include <mutex>
#include <ringcounter.hpp>

using namespace std;

template <typename T, int L>
class ringbuffer {
 public:
  explicit ringbuffer() : _rb(unique_ptr<T[]>(new T[L])), _head(L), _tail(L) {}
  ~ringbuffer() {}

  bool is_full(void) const { return (_tail == _head + 1); }

  bool is_empty(void) const { return (_head == _tail); }

  T* begin() const { return &_rb[_tail.get()]; }

  T* end() const { return &_rb[_head.get()]; }

  T* operator++() { return &_rb[++_tail]; }

  int write(T data) {
    lock_guard<mutex> lock(_m);

    if (is_full()) return 1;

    _rb[_head++] = data;
    return 0;
  }

  int read(T& data) {
    lock_guard<mutex> lock(_m);

    if (is_empty()) return 1;

    data = _rb[_tail++];
    return 0;
  }

 private:
  unique_ptr<T[]> _rb;
  mutex _m;

  ringcounter _head;
  ringcounter _tail;

  const unsigned int _len = L;
};