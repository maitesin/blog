#include <iostream>

int main() {
  int x = 1;
  auto my_lambda = [&z = x]() { z += 1; };
  my_lambda();
  std::cout << x << std::endl;
  return 0;
}
