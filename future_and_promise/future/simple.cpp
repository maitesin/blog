#include <iostream>
#include <future>

int accum_up_to(int value) {
  int accum = 0;
  for (int i = 0; i <= value; ++i) {
    accum += i;
  }
  return accum;
}


int main()
{
  std::future<int> f = std::async(std::launch::async, accum_up_to, 50);

  std::cout << "Calculated a value of: " << f.get() << std::endl;

  return 0;
}
