#include "user_thread.hpp"
#include <iostream>
#include <thread>

UserThread::UserThread(boost::asio::io_context& io_context, std::string user_name)
    : io_context(io_context), user_name(user_name) {}

void UserThread::start() {
  std::cout << "Thread for " << user_name << " started!" << std::endl;
  // Implement further actions for the user
}
