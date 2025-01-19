#include <stdio.h>
#include <signal.h>

void handler(int signum) {
  printf("Signal number %d recieved\n", signum);
  while (true) {};
}

int main() {
  signal(SIGINT, &handler);
  signal(SIGQUIT, &handler);

  while (true) {};

}
