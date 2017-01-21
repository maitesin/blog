#include <iostream>
#include <boost/asio.hpp>

int main()
{
  boost::asio::io_service service;

  service.post([](){std::cout << "1" << std::endl;});
  service.post([](){std::cout << "2" << std::endl;});
  service.post([](){std::cout << "3" << std::endl;});
  service.post([](){std::cout << "4" << std::endl;});
  service.post([](){std::cout << "5" << std::endl;});
  service.post([](){std::cout << "6" << std::endl;});

  service.run();

  return 0;
}
