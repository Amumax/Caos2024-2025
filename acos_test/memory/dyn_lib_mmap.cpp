#include <cstdlib>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  const char* file_name = argv[1];
  double arg = strtod(argv[2], nullptr);

  int fd = open(file_name, O_RDONLY);
  struct stat st = {};
  fstat(fd, &st);

  void* addr = mmap(nullptr, st.st_size, PROT_READ|PROT_EXEC, MAP_PRIVATE, fd, 0);
  double (*func)(double) = (double (*)(double)) ((char*)addr + 0x40);

  close(fd);
  double result = func(arg);
  printf("func(%f) = %f\n", arg, result);
  munmap(addr, st.st_size);
}
