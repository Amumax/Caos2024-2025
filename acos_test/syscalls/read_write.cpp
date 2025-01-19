#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <errno.h>
#include <string>


int main() {
  const int size = 100;

  char str[size];
  read(0, str, size);
  
  int len = strlen(str);

  for (int i = len; i > 0; ) {
    ssize_t offset = write(3, str + len - i, i);
    if (offset >= 0) {
      i -= offset;
      continue;
    }

    auto err_code = std::to_string(errno);
    if (errno != EBADF) {
      // do something
    }
    write(2, err_code.data(), strlen(err_code.data()));
    exit(1);
  }
}
