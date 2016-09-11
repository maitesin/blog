#include <iostream>
#include <functional>
#include <thread>

void accum_up_to(int value, int & result) {
  int accum = 0;
  for (int i = 0; i <= value; ++i) {
    accum += i;
  }
  result = accum;
}

int main()
{
  int result1, result2;
  std::thread t1(accum_up_to, 50, std::ref(result1));
  std::thread t2(accum_up_to, 40, std::ref(result2));

  t1.join();
  t2.join();

  std::cout << "Calculated a value of: " << result1 << std::endl;
  std::cout << "Calculated a value of: " << result2 << std::endl;

  return 0;
}
