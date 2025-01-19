#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main() {
  
  int fd = open("./output.txt", O_WRONLY | O_CREAT, 0666);
  printf("%d\n", fd);

  int offset = lseek(fd, 50, SEEK_SET);
  const char* buf = "Hello world!";

  int res = write(fd, buf, 10);
  printf("%d\n", res);

  printf("%d", errno);

  close(fd);
}
