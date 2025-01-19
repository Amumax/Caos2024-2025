#include <thread>
#include <iostream>

void job(char c) {
  for (int i = 0; i < 10; ++i) {
    std::cout << c << ' ';
  }
}

int main() {
  std::thread t(job, 'a');

  job('b');
}
