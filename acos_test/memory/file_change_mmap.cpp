#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>


int main() {
  int fd = open("example.txt", O_RDWR);
  if (fd == -1) {
    exit(1);
  }
  
  struct stat sb;
  if (fstat(fd, &sb) == -1) {
    exit(1);
  }

  char* data = (char*)mmap(nullptr, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (data == MAP_FAILED) {
    exit(1);
  }

  data[0] = 'X';

  std::cout << (void*) data << std::endl;
  printf("%s\n", data);
  getchar();

  if (msync(data, sb.st_size, MS_SYNC) == -1) {
    exit(1);
  }

  munmap(data, sb.st_size);
}
