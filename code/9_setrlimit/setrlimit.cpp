#include <iostream>
#include <sys/resource.h>
int main()
{
  struct rlimit rl;
  int result;
  const rlim_t kStackSize = 210 * 1024 * 1024; // min stack size = 16 MB
  result = getrlimit(RLIMIT_STACK, &rl);
  if (result != 0)
  {
    std::cerr << "Failed to get current stack size\n";
    abort();
  }
  std::cerr << rl.rlim_cur << '\n';
  if (rl.rlim_cur < kStackSize)
  {
    rl.rlim_cur = kStackSize;
    result = setrlimit(RLIMIT_STACK, &rl);
    if (result != 0)
    {
      std::cerr << "Failed to get bigger stack size\n";
      abort();
    }
    std::cerr << "Stack size is successfully set to " << kStackSize << '\n';
  }
}
// Вывод:
// 8388608
// Stack size is successfully set to 2