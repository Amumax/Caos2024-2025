#include <iostream>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        std::cout << "I was born!";                                 // will be printed
        char *argv[] = {"/usr/bin/ls", "/directory/address", NULL}; // the last one must be NULL!
        char *envp[] = {NULL};                                      // environment variables
        execve("/usr/bin/ls", argv, envp);                          // releasing buffers

        std::cout << "After execve" << std::endl; // will not be printed
    }
    else
    {
        std::cout << "I am parent!"; // will be printed
    }
}
