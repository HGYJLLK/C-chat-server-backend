#include "user_auth.hpp"
#include <mysqlx/xdevapi.h>

UserAuth::UserAuth(DBConnection& db) : db(db) {}

bool UserAuth::registerUser(const std::string& username, const std::string& password) {
  try {
    mysqlx::Schema db_schema = db.getSession().getSchema("user_auth_db");
    mysqlx::Table users_table = db_schema.getTable("users");

    // Check if user already exists
    mysqlx::RowResult res = users_table.select("username").where("username = :username").bind("username", username).execute();
    if (res.count() > 0) {
      std::cout << "User already exists!" << std::endl;
      return false;
    }

    // Insert new user
    users_table.insert("username", "password").values(username, password).execute();
    std::cout << "User registered successfully!" << std::endl;
    return true;
  }
  catch (const mysqlx::Error& err) {
    std::cerr << "Error registering user: " << err.what() << std::endl;
    return false;
  }
}

bool UserAuth::loginUser(const std::string& username, const std::string& password) {
  try {
    mysqlx::Schema db_schema = db.getSession().getSchema("user_auth_db");
    mysqlx::Table users_table = db_schema.getTable("users");

    // Check if user exists and password matches
    mysqlx::RowResult res = users_table.select("username", "password").where("username = :username AND password = :password")
                                .bind("username", username).bind("password", password).execute();

    if (res.count() == 1) {
      std::cout << "Login successful!" << std::endl;
      return true;
    } else {
      std::cout << "Invalid credentials!" << std::endl;
      return false;
    }
  }
  catch (const mysqlx::Error& err) {
    std::cerr << "Error logging in user: " << err.what() << std::endl;
    return false;
  }
}
