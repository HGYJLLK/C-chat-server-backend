#ifndef CHAT_SERVER_HPP
#define CHAT_SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include <thread>
#include <iostream>
#include <mutex>

class ChatServer {
public:
  ChatServer(boost::asio::io_context& io_context, short port);
  void start();

private:
  void handle_client(boost::asio::ip::tcp::socket socket);

  boost::asio::io_context& io_context;
  boost::asio::ip::tcp::acceptor acceptor;
  std::mutex mtx;
};

#endif // CHAT_SERVER_HPP
