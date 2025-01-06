#include <iostream>
#include <thread>
#include <memory>

class A
{
private:
    friend void thread_foo();
    void foo()
    {
        std::cout << "Hello" << std::endl;
    }
};

void thread_foo()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo, a);
    t.join();
}

int main(void)
{
    thread_foo();
}