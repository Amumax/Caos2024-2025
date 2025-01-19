#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void sigpipe_handler(int signum) {
  printf("Recieved sigpipe!\n");
  _exit(1);
}

int main(int argc, char* argv[]) {

  signal(SIGPIPE, &sigpipe_handler);
  
  int pipefd[2];
  pipe(pipefd);

  int cpid = fork();
  if (cpid == 0) {
    close(pipefd[1]);
     
    close(pipefd[0]);
    sleep(5);
    printf("I'm child!\n");
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
