#include <unistd.h>
#include <cstring>
#include <errno.h>
#include <string>

int main() {
    const char *str = "Hello world!";
    long i = write(3, str, strlen(str));
    if (i == -1) {
      write(2, "fail!", 5);
      std::string err = std::to_string(errno);
      write(1, err.data(), err.size());
    } else {
      while (strlen(str) - i > 0) {
      i += write(1, str, strlen(str) - i);
    }
  }
}