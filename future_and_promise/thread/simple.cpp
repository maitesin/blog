#include <iostream>
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
  int result;
  std::thread t1(accum_up_to, 50, std::ref(result));

  t1.join();

  std::cout << "Calculated a value of: " << result << std::endl;

  return 0;
}
