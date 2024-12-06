#ifndef USER_AUTH_HPP
#define USER_AUTH_HPP

#include "db_connection.hpp"
#include <string>
#include <iostream>

class UserAuth {
public:
  UserAuth(DBConnection& db);
  bool registerUser(const std::string& username, const std::string& password);
  bool loginUser(const std::string& username, const std::string& password);

private:
  DBConnection& db;
};

#endif // USER_AUTH_HPP
