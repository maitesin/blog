#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
  // Check provided parameters
  if (argc != 4) {
    std::cerr << "Error. Bad number of parameters" << std::endl;
    std::cerr << "Usage: " << argv[0] << " <hostname> <port|service> <message>" << std::endl;
    exit(-1);
  }

  // Error to not throw exception
  boost::system::error_code not_throw;

  // Resolve hostname and port
  boost::asio::io_service service;
  tcp::resolver resolver(service);
  tcp::resolver::query query(argv[1], argv[2]);
  tcp::resolver::iterator endpoint = resolver.resolve(query, not_throw);
  if (not_throw) {
    std::cerr << "Error resolving host(" << not_throw.value() << "): "<< not_throw.message() << std::endl;
    return 1;
  }

  // Socket and connection
  tcp::socket socket(service);
  boost::asio::connect(socket, endpoint, not_throw);
  if (not_throw) {
    std::cerr << "Error connecting(" << not_throw.value() << "): "<< not_throw.message() << std::endl;
    return 1;
  }

  // Send a message to the end point
  std::string message = {argv[3]};
  boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all(), not_throw);
  if (not_throw) {
    std::cerr << "Error sending(" << not_throw.value() << "): "<< not_throw.message() << std::endl;
    return 1;
  }

  // Read a message from the end point
  boost::asio::streambuf response;
  boost::system::error_code error = boost::asio::error::eof;
  do {
    boost::asio::read(socket, response, error);
  } while(error != boost::asio::error::eof);

  // Close socket
  socket.close();

  // Show the received message
  std::istream received(&response);
  std::cout << received.rdbuf() << std::endl;

  return 0;
}
