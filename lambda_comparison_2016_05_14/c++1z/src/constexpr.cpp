#include <iostream>

int main() {
  constexpr auto multi = [](int a, int b){ return a * b; };
  static_assert(multi(3,7) == 21, "3x7 == 21");
  static_assert(multi(4,5) == 15, "5x5 != 15");
  return 0;
}
