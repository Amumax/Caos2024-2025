#include <unistd.h>
#include <cstring>
#include <errno.h>

int main() {
  const char *str = "Hello world!";
  long i = write(3, str, strlen(str));
  if (i == -1) {
    write(2, "fail!", 5);
  } else {
    while (strlen(str) - i > 0) {
      i += write(1, str, strlen(str) - i);
    }
  }
}