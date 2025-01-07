// A deadlock is a situation in computer science and concurrent programming
// where two or more processes are unable to proceed because each is waiting for
// the other to release a resource.

#include <mutex>

class some_big_object {};

void swap(some_big_object &lhs, some_big_object &rhs);

class X {
private:
  some_big_object some_detail;
  std::mutex m;

public:
  X(some_big_object const &sd) : some_detail(sd) {}
  friend void swap(X &lhs, X &rhs) {
    if (&lhs == &rhs)
      return;
    std::lock(lhs.m, rhs.m);                                    // 1
    std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock); // 2
    // std::adopt_lock assume the calling thread already has ownership of the
    // mutex
    std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock); // 3
    swap(lhs.some_detail, rhs.some_detail);
  }

  void swap_cpp17(const X &lhs, const X &rhs) {
    if (&lhs == &rhs)
      return;
    std::scoped_lock guard(lhs.m, rhs.m); // 1
    swap_cpp17(lhs.some_detail, rhs.some_detail);
  }
};

// guidelines for avoiding deadlock
// AVOID NESTED LOCKS
// AVOID CALLING USER-SUPPLIED CODE WHILE HOLDING A LOCK
// ACQUIRE LOCKS IN A FIXED ORDER
// USE A LOCK HIERARCH
// EXTENDING THESE GUIDELINES BEYOND LOCKS