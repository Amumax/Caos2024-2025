#include <iostream>
#include <unistd.h>

int main() {
  for (int i=0; i < 1000; ++i) {
  std::cout << i;
  }
  _exit(0);
}