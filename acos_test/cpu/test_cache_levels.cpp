#include <iostream>


int main(int argc, char* argv[]) {
  int N = std::stoi(argv[1]) * 8 * 1024;
  int* arr = new int[N];

  int steps = 64 * 1024 * 1024;
  int length_mod = N - 1;

  for (int j = 0; j < steps; ++j) {
    arr[(j * 16) & length_mod]++;
  }
}
