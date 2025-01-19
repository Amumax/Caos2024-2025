#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main() {
  
  std::cout << "Hello! " << getpid();
  int pid = fork();

  if (pid != 0) {
    std::cout << "I'm parent with id " << getpid() << std::endl;
    char* argv[] = {"/usr/bin/ls", ".", "-l", nullptr};
    char* envp[] = {nullptr};
    // execve("/usr/bin/ls", argv, envp);

    sleep(1);
    int x;
    int pid = wait(&x);
    std::cout << "Child " << pid << " exited with code " << x << std::endl;

    std::cout << "After execve" << std::endl;
  } else {
    std::cout << "I'm child with id " << getpid() << std::endl;
  }

}
