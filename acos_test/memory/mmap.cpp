#include <sys/mman.h>
#include <iostream>

int main() {
  void* ptr = mmap(nullptr, 1, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  std::cout << ptr << '\n';

  // getchar();
  int res = munmap(ptr, 1);
  if (res == -1) {
    std::cout << "Failed to unmap " << ptr << std::endl;
    throw;
  }
  return 0;
}
