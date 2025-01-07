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
    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
    // defer_lock_t	do not acquire ownership of the mutex
    std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
    std::lock(lock_a, lock_b); // mutexes are locked here
    swap(lhs.some_detail, rhs.some_detail);
  }
};

/*
void get_and_process_data() {
  std::unique_lock<std::mutex> my_lock(the_mutex);
  some_class data_to_process = get_next_data_chunk();
  my_lock.unlock(); // 1 不要让锁住的互斥量越过process()函数的调用
  result_type result = process(data_to_process);
  my_lock.lock(); // 2 为了写入数据，对互斥量再次上锁
  write_result(data_to_process, result);
}
*/