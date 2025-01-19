#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
  int fd1 = open("./input.txt", O_RDONLY);

  char buf[100];
  read(fd1, buf, 10);

  int fd2 = open("./output.txt", O_WRONLY | O_CREAT, 0666);
  write(fd2, buf, 10);
  write(1, buf, 10);

  close(fd1);
  close(fd2);
}
