#include <iostream>
#include <memory>
#include <thread>

class A {
public:
  void foo() { std::cout << "Hello" << std::endl; }
};

int main(void) {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::thread t(&A::foo, a);
  t.join();
}

struct big_object {
public:
  void prepare_data(int i);
};

void process_big_object(std::unique_ptr<big_object>);

void goo() {
  std::unique_ptr<big_object> p(new big_object);
  p->prepare_data(42);
  std::thread t(process_big_object, std::move(p));
}