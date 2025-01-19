// #include <iostream>
#include <unistd.h>

void* __dso_handle = 0;

int main() {
  //int x;
  //std::cin >> x;
  //std::cout << x + 5 << '\n';
  write(1, "Hello!", 6);
  _exit(0);
}
