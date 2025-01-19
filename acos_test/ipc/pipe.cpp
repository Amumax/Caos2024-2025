#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
  char buf[1000];
  int pipefd[2];
  pipe(pipefd);

  int cpid = fork();
  if (cpid == 0) {
    close(pipefd[1]);

    while (read(pipefd[0], &buf, 1) > 0) {
      write(1, &buf, 1);
    }

    write(1, "\n", 1);
    close(pipefd[0]);
    _exit(0);
  } else {
    close(pipefd[0]);
    sleep(1);
    write(pipefd[1], argv[1], strlen(argv[1]));
    close(pipefd[1]);
    wait(nullptr);
    _exit(0);
  }
}
