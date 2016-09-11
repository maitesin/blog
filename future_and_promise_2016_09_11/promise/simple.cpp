#include <iostream>
#include <functional>
#include <thread>
#include <future>

void accum_up_to(std::future<int>& f) {
  std::cout << "Started accum_up_to method" << std::endl;
  int accum = 0;
  int value = f.get();
  for (int i = 0; i <= value; ++i) {
    accum += i;
  }
  std::cout << "Calculated a value of: " << accum << std::endl;
}


int main()
{
  int limit;
  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::thread t(accum_up_to, std::ref(f));

  std::cout << "Introduce the limit:" << std::endl;
  std::cin >> limit;

  p.set_value(limit);
  t.join();

  return 0;
}
