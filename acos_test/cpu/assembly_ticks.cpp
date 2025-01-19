#include <stdio.h>

unsigned long long rdtsc(void) {
  unsigned long long tsc;
  asm volatile("rdtsc" : "=A" (tsc));
  return tsc;
}

int main() {
  unsigned long long start, end, ticks;

  start = rdtsc();
  int x = 0;
  for (int i = 0; i < 100; ++i) {
    x += 5;
  }
  end = rdtsc();

  ticks = end - start;
  printf("Ticks: %llu\n", ticks);

  return 0;
}
