#include <HierarchicalMutex.h>

hierarchical_mutex high_level_mutex(10000); // 1
hierarchical_mutex low_level_mutex(5000);   // 2
hierarchical_mutex other_mutex(6000);       // 3

int do_low_level_stuff();

int low_level_func() {
  std::lock_guard<hierarchical_mutex> lk(low_level_mutex); // 4
  return do_low_level_stuff();
}

void high_level_stuff(int some_param);

void high_level_func() {
  std::lock_guard<hierarchical_mutex> lk(high_level_mutex); // 6
  high_level_stuff(low_level_func());                       // 5
}

void thread_a() // 7
{
  high_level_func();
}

void do_other_stuff();

void other_stuff() {
  high_level_func(); // 10
  do_other_stuff();
}

void thread_b() // 8
{
  std::lock_guard<hierarchical_mutex> lk(other_mutex); // 9
  other_stuff();
}