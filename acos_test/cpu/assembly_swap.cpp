#include <stdio.h>


int main() {
  int src = 1;
  int dst = 2;

   asm volatile ("mov %0, %%eax\n\t"
                  "mov %1, %%ebx"
      : :"r" (dst), "r" (src));

   asm volatile ("mov %%eax, %1\n\t"
                "mov %%ebx, %0"
      : "=r" (dst), "=r"(src));

  printf("src: %d\ndst: %d\n", src, dst);
}
