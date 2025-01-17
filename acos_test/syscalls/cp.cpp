#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[])
{
    char buffer[1024];
    int fd_read, fd_write;
    fd_read = open(argv[1], O_RDONLY);

    if (fd_read == -1)
    {
        const char* msg = "Couldn't open file";
        write(2, msg, strlen(msg));
        exit(1);
    }
    fd_write = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0744);
    if (fd_write == -1)
    {
        const char* msg = "Couldn't open file";
        write(2, msg, strlen(msg));
        exit(1);
    }

    int n_read;
    while ((n_read = read(fd_read, buffer, sizeof(buffer))) > 0) {
        write(fd_write, buffer, n_read);
    }

    close(fd_read);
    close(fd_write);
    return 0;
}
