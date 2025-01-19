#include <iostream>
#include <vector>

int main() {
  int x; 
  std::cin >> x;
  x += 10;
  std::cout << x << '\n';
  x -= 10;
  std::cout << x << '\n';

  std::vector<int> v(100);

  std::cout << v[10000000] << std::endl;
}
