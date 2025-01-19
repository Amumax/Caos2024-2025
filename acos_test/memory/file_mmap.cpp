#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>


int main() {
  int fd = open("example.txt", O_RDONLY);
  if (fd == -1) {
    exit(1);
  }
  
  struct stat sb;
  if (fstat(fd, &sb) == -1) {
    exit(1);
  }

  char* data = (char*)mmap(nullptr, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (data == MAP_FAILED) {
    exit(1);
  }

  std::cout << (void*) data << std::endl;
  printf("%s\n", data);
  getchar();

  munmap(data, sb.st_size);
}
