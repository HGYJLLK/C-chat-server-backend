#include "db_connection.hpp"
#include "user_auth.hpp"
#include "chat_server.hpp"
#include "user_thread.hpp"
#include <boost/asio.hpp>
#include <iostream>

int main() {
  // Database connection
  DBConnection db("localhost", "root", "", "user_auth_db");

  // User Authentication
  UserAuth auth(db);
  if (!auth.loginUser("user1", "password")) {
    if (!auth.registerUser("user1", "password")) {
      return -1;
    }
  }

  // Start chat server
  boost::asio::io_context io_context;
  ChatServer server(io_context, 8080);
  std::thread chat_thread([&io_context](){ io_context.run(); });

  // Start user threads
  UserThread user(io_context, "user1");
  user.start();

  chat_thread.join();
  return 0;
}
