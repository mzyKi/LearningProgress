#include <iostream>
#include <thread>

void foo(int &x)
{
    x += 1;
}

int main(void)
{
    int i = 1;
    std::thread t(foo, std::ref(i));
    if (t.joinable())
    {
        t.join();
    }
    std::cout << i << std::endl;
    return 0;
}