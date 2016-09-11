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
  std::future<int> f1 = std::async(std::launch::async, accum_up_to, 50);
  std::future<int> f2 = std::async(std::launch::async, accum_up_to, 40);

  std::cout << "Calculated a value of: " << f1.get() << std::endl;
  std::cout << "Calculated a value of: " << f2.get() << std::endl;

  return 0;
}
