#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() {

    int fd = open("./output.txt", O_WRONLY | O_CREAT);

    dup2(fd, 1);

    std::cout << "Blablabla";
    std::cout.flush();

    close(fd);
}
