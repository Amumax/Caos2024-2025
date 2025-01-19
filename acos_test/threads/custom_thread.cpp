#include <iostream>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sched.h>


class Thread {
  private:
    using Callable = void(*)();

  public:
    Thread(Callable func) : func(func) {
      const int STACK_SIZE = 8392704;

      stack = (char*) malloc(STACK_SIZE);
      
      pid = clone(threadRoutine, stack + STACK_SIZE, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD | SIGCHLD, (void*)func);
    }

    void join() {
      int status;
      waitpid(pid, &status, 0);
      pid = -1;
    }

    ~Thread() {
      if (pid != -1) {
        std::terminate();
      }
      munmap(stack, 8 * 1024 * 1024);
    }

  private:
    static int threadRoutine(void* func) {
      Callable routine = reinterpret_cast<Callable>(func);
      routine();
      return 0;
    }
    Callable func;
    char* stack;
    int pid = -1;
};

void f() {
  for (int i = 0; i < 100; ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Thread t(f);

  f();

  t.join();
}
