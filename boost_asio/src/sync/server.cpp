#include <iostream>
#include <string>
#include <algorithm>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, const char *argv[])
{
  // Check provided parameters
  if (argc != 2) {
    std::cerr << "Error. Bad number of parameters" << std::endl;
    std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
    exit(-1);
  }
  // Get the port from the parameters
  uint16_t port = std::stoul(argv[1]);

  // Error to not throw exception
  boost::system::error_code not_throw;

  // Socket and acceptor
  boost::asio::io_service service;
  tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), port));
  tcp::socket socket(service);
  acceptor.accept(socket, not_throw);
  if (not_throw) {
    std::cerr << "Error when binding the port in the socket" << std::endl;
    return 1;
  }

  // Read a message
  char buf[512];
  std::ostringstream oss;
  boost::system::error_code error = boost::asio::error::eof;
  do {
    socket.read_some(boost::asio::buffer(buf), error);
    oss << buf;
  } while(error && error != boost::asio::error::eof);

  // Reverse the received message
  std::string original = oss.str();
  std::reverse(std::begin(original), std::end(original));

  // Write the reversed message
  socket.write_some(boost::asio::buffer(original), not_throw);
  if (not_throw) {
    std::cerr << "Error sending(" << not_throw.value() << "): " << not_throw.message() << std::endl;
    return 1;
  }

  // Close socket
  socket.close();

  return 0;
}
