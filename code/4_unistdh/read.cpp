#include <unistd.h>

int main() {
  char buf[100];
  read(0, buf, 10);
  write(2, "hello world ", 12);
  write(2, buf, 10);
  _exit(0);
}