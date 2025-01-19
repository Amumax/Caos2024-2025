#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
    char buf[1024];

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);

    int bytes_read;
    while ((bytes_read = read(0, buf, sizeof(buf))) > 0) {
        if (bytes_read == -1) {
            write(2, "Error!", 6);
            exit(1);
        }
       write(1, buf, bytes_read);
       write(fd, buf, bytes_read);
    }

    close(fd);
}
