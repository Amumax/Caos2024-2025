#include <iostream>

extern "C" int is_prime(int n);

int main() {
  int number;

  std::cout << "Enter a number: ";
  std::cin >> number;

  int result = is_prime(number);

  if (result) {
    std::cout << number << " is a prime number" << std::endl;
  } else {
    std::cout << number << " isn't a prime number" << std::endl;
  }
}
