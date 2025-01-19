#include <sys/mman.h>
#include <iostream>
#include <vector>

int main() {
  std::vector<char> v;

  for (int i = 0; i < 1000000; ++i) {
    v.push_back(i);
  }

  std::cout << "Vector starts at " << (int *)&v[0] << std::endl;
  std::cout << mprotect(&v[0] - 16, 10000, PROT_READ|PROT_WRITE|PROT_EXEC) << std::endl;

  v[0] = 0x33;
  void (*f)() = (void(*)()) &v[0];
  f();

}
