#include <iostream>

int main() {
  auto my_lambda = [](auto &a, auto &b) { return a < b; };
  float af = 1.5, bf = 2.0;
  int ai = 3, bi = 1;
  std::cout << "Float: " << my_lambda(af, bf) << std::endl;
  std::cout << "Integer: " << my_lambda(ai, bi) << std::endl;
  return 0;
}
