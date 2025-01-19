#include <sys/resource.h>
#include <iostream>


int main() {

  const rlim_t kStackSize = 210 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result != 0) {
    std::cout << "Failed to get current stack size\n";
    abort();
  }

  std::cout << rl.rlim_cur << std::endl;

  if (rl.rlim_cur < kStackSize) {
    rl.rlim_cur = kStackSize;
    result = setrlimit(RLIMIT_STACK, &rl);

    if (result != 0) {
      std::cout << "Failed to enlarge stack\n";
      abort();
    }
    std::cout << "Stack size is set to " << kStackSize << std::endl;
  }
}
