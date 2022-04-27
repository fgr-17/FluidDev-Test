/**
 * @file ringbuffer.hpp
 * @brief class defined to control circular buffers and its operators
 * @author Federico Roux (rouxfederico@gmail.com)
 */

#include <iostream>
#include <memory>
#include <mutex>
#include <ringcounter.hpp>

using namespace std;

template <typename T, int L>

class ringbuffer {
 public:
  explicit ringbuffer()
      : _rb(unique_ptr<T[]>(new T[L])), _len(L), _head(0), _tail(0) {}
  ~ringbuffer() {}

  bool is_full(void) const {
    cout << "tail: " << _tail.get() << endl;
    cout << "head: " << _head.get() << endl;
    cout << "head + 1: " << (_head + 1) << endl;
    return (_tail == _head + 1);
  }

  bool is_empty(void) const { return (_head == _tail); }

  int write(T data) {
    lock_guard<mutex> lock(_m);

    if (is_full()) return 1;

    _rb[_head++] = data;
    return 0;
  }

  int read(T& data) {
    lock_guard<mutex> lock(_m);

    if (is_empty()) return 1;

    _tail++;
    data = _rb[_tail];
    return 0;
  }

 private:
  unique_ptr<T[]> _rb;
  mutex _m;

  ringcounter _head{5};
  ringcounter _tail{5};

  const unsigned int _len = L;
};