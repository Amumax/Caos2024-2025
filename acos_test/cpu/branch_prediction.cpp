#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c) {
    data[c] = std::rand() % 256;
  }

  // std::sort(data, data + arraySize);
  
  clock_t start = clock();
  long long sum = 0;
  for (unsigned i = 0; i < 100000; ++i) {
    for (unsigned c = 0; c < arraySize; ++c) {
      if (data[c] >= 128) {
        sum += data[c];
      }
    }
  }

  double elapsed_tme = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsed_tme << '\n';
  std::cout << "sum = " << sum << '\n';
}
