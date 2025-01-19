#include <thread>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <unistd.h>

int x = 0;
int cnt = 0;

void foo()
{
    int tid = gettid();
    while (true)
    {
        x = x + 1;
        x = x - 1;
        ++cnt;

        char* str;
        sprintf(str, "Tid: %d, x: %d\n", tid, x);
        write(1, str, strlen(str));

        assert(x == 0);
    }
}

int main()
{
    std::thread t(foo);
    std::thread t2(foo);

    t.join();
    t2.join();
}
