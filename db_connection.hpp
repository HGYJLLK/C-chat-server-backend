#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <mysqlx/xdevapi.h>
#include <string>
#include <iostream>

class DBConnection {
public:
  DBConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& db_name);
  ~DBConnection();

  mysqlx::Session& getSession();

private:
  mysqlx::Session* session;
  std::string host, user, password, db_name;
};

#endif // DB_CONNECTION_HPP
