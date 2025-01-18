#include <iostream> 
#include <unistd.h>
int main()
{
    std::cout << "Hello! "; // in both of procesess this message will be printed!!!
    int pid = fork();
    if (pid == 0)
    {
        std::cout << "I was born!" << std::endl;
    }
    else
    {
        std::cout << "I am parent!" << std::endl;
    }
}