#include <unistd.h>

int main() {
  const char *str = "Hello world!";
  write(1, str, 12);
}