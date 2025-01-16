#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  const char* file_name = argv[1];
  double argument = strtod(argv[2], NULL);
  int fd = open(file_name, O_RDONLY);
  struct stat st = {};
  fstat(fd, &st);
  void* addr = mmap(NULL, st.st_size,
  PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);
  double (*func)(double) = (double (*)(double))((char*)addr + 0x40);
  close(fd);
  double result = func(argument);
  printf("func(%f) = %f\n", argument, result);
  munmap(addr, st.st_size);
}