#include "chat_server.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>

ChatServer::ChatServer(boost::asio::io_context& io_context, short port)
    : io_context(io_context), acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void ChatServer::start() {
  std::cout << "Chat server started on port 8080" << std::endl;
  while (true) {
    boost::asio::ip::tcp::socket socket(io_context);
    acceptor.accept(socket);
    std::thread(&ChatServer::handle_client, this, std::move(socket)).detach();
  }
}

void ChatServer::handle_client(boost::asio::ip::tcp::socket socket) {
  try {
    boost::asio::streambuf buf;
    std::istream input(&buf);
    std::string message;

    while (true) {
      std::getline(input, message);
      if (message == "exit") {
        break;
      }
      std::lock_guard<std::mutex> lock(mtx);
      std::cout << "Received: " << message << std::endl;
      boost::asio::write(socket, boost::asio::buffer("Message received"));
    }
  }
  catch (const std::exception& e) {
    std::cerr << "Client error: " << e.what() << std::endl;
  }
}
