#include <sys/mman.h>
#include <iostream>


int main() {
  char* ptr = (char*)mmap((void*)0x4a7febb7d000, 10000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  std::cout << (void*)ptr << std::endl;
  getchar();
  munmap(ptr, 10000);
}
