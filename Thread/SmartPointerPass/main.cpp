#include <iostream>
#include <thread>
#include <memory>

class A
{
public:
    void foo()
    {
        std::cout << "Hello" << std::endl;
    }
};

int main(void)
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo, a);
    t.join();
}