#include "db_connection.hpp"

DBConnection::DBConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& db_name)
    : host(host), user(user), password(password), db_name(db_name) {
  try {
    session = new mysqlx::Session(host, 33060, user, password, db_name);
    std::cout << "Database connected successfully!" << std::endl;
  }
  catch (const mysqlx::Error& err) {
    std::cerr << "Database connection error: " << err.what() << std::endl;
  }
}

DBConnection::~DBConnection() {
  if (session) {
    session->close();
    delete session;
  }
}

mysqlx::Session& DBConnection::getSession() {
  return *session;
}
