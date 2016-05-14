#include <iostream>

int main() {
  int i = 1;
  auto copy = [=](){ std::cout << i << std::endl; };
  auto ref = [&](){ std::cout << i << std::endl; };
  copy();
  ref();
  ++i;
  copy();
  ref();
  return 0;
}
