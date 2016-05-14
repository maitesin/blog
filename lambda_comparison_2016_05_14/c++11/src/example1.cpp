#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto my_lambda = [](int x) { return x + 1; };
  std::transform(v.begin(), v.end(), v.begin(), my_lambda);
  for (auto &value : v) {
    std::cout << value << std::endl;
  }
  return 0;
}
