#include <iostream>

const int N = 64 * 1024 * 1024;
int a[N];

int main() {

  int step = 4;

  for (int k = 0; k < 1; ++k) {
    for (int i = 0; i < N; i += step) {
      a[i] *= 3;
    }
  }
}
