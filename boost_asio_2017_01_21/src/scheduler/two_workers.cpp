#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <boost/asio.hpp>

int main()
{
  std::vector<std::thread> worker;
  boost::asio::io_service service;

  service.post([](){std::cout << "1" << std::endl;});
  service.post([](){std::cout << "2" << std::endl;});
  service.post([](){std::cout << "3" << std::endl;});
  service.post([](){std::cout << "4" << std::endl;});
  service.post([](){std::cout << "5" << std::endl;});
  service.post([](){std::cout << "6" << std::endl;});

  for (int i = 0; i < 2; i++) {
    worker.push_back(std::thread([&](){ service.run(); }));
  }

  std::for_each(std::begin(worker), std::end(worker), [](std::thread &t){t.join();});

  return 0;
}
