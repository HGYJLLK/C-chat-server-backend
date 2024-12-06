#ifndef USER_THREAD_HPP
#define USER_THREAD_HPP

#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <thread>

class UserThread {
public:
  UserThread(boost::asio::io_context& io_context, std::string user_name);
  void start();

private:
  boost::asio::io_context& io_context;
  std::string user_name;
};

#endif // USER_THREAD_HPP
