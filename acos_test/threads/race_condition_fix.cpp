#include <thread>
#include <mutex>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <unistd.h>

int x = 0;
std::mutex m;

void foo()
{
    int tid = gettid();
    while (true)
    {
        m.lock();
        x = x + 1;
        x = x - 1;

        char* str;
        sprintf(str, "Tid: %d, x: %d\n", tid, x);
        write(1, str, strlen(str));

        assert(x == 0);
        m.unlock();
    }
}

int main()
{
    std::thread t(foo);
    std::thread t2(foo);

    t.join();
    t2.join();
}
