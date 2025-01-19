#include <stdio.h>
#include <signal.h>

int *p = nullptr;
int a = 0;

void handler(int signum) {
  printf("Signal number %d recieved\n", signum);
  p = &a;
}

int main() {
  signal(SIGSEGV, &handler);

  *p = 5;
}
