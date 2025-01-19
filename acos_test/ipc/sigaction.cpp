#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsev_handler(int signum) {
  printf("Segfault occured.\n");
  exit(1);
}

int main() {
  struct sigaction sa;
  sa.sa_handler = sigsev_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  if (sigaction(SIGSEGV, &sa, nullptr) == -1) {
    perror("sigaction");
    exit(1);
  }

  int* ptr = nullptr;
  *ptr = 10;

  printf("Continuing execution after segfault.\n");
}
