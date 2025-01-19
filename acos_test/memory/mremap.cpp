#include <iostream>
#include <sys/mman.h>


int main() {
  void* ptr = mmap(nullptr, 1000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  std::cout << "ptr address: " << ptr << std::endl;
  getchar();

  void* ptr_remapped = mremap(ptr, 1000, 10000, MREMAP_MAYMOVE);
  std::cout << "remapped address: " << ptr_remapped << std::endl;
  getchar();
  int res = munmap(ptr_remapped, 10000);
  if (res == -1) {
    std::cout << "Failed to unmap " << ptr_remapped << std::endl;
  }
}
