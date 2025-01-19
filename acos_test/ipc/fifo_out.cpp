#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {

  int fd = open("./myfifo", O_APPEND | O_WRONLY);
  int res = 0;

  if (fd == -1 && errno == ENOENT) {
    errno = 0;
    res = mkfifo("./myfifo", 0666);
    if (res < 0) {
      perror("mkfifo");
      exit(1);
    }
    fd = open("./myfifo", O_APPEND | O_WRONLY);
  }

  if (fd == -1) {
    perror("open");
    exit(1);
  }

  res = write(fd, argv[1], strlen(argv[1]));
  if (res < 0) {
    perror("write");
    exit(1);
  }
}
