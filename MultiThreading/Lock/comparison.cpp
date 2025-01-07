#include <mutex>

class Y {
private:
  int some_detail;
  mutable std::mutex m;
  int get_detail() const {
    std::lock_guard<std::mutex> lock_a(m); // 1
    return some_detail;
  }

public:
  Y(int sd) : some_detail(sd) {}
  friend bool operator==(Y const &lhs, Y const &rhs) {
    if (&lhs == &rhs)
      return true;
    int const lhs_value = lhs.get_detail(); // 2
    int const rhs_value = rhs.get_detail(); // 3
    return lhs_value == rhs_value;          // 4
  }
};