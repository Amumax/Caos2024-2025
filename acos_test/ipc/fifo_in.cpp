#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {

  int fd = open("./myfifo", O_RDONLY);

  if (fd == -1) {
    perror("open");
    exit(1);
  }

  char buf[1000];
  int bytes = 0;
  while ((bytes = read(fd, buf, 1000)) > 0) {
    write(1, buf, bytes);
  }
}
