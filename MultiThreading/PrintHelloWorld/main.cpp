#include <iostream>
#include <thread>

void printHelloWorld(std::string Msg) { std::cout << Msg << std::endl; }

int main(void) {
  std::thread thread1(printHelloWorld, "Hello World");
  if (thread1.joinable()) {
    thread1.join();
  }
  // thread1.detach();
  return 0;
}