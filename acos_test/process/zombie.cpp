#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main() {
  
  int pid = fork();

  if (pid == 0) {
    std::cout << "I'm child with id " << getpid() << std::endl;
  } else {
    std::cout << "I'm parent with id " << getpid() << std::endl;
    while (true) {};
  }

}
