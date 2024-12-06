cmake_minimum_required(VERSION 3.10)
project(YourExecutableName)

# Explicitly set MySQL Connector paths
set(MYSQL_CONNECTOR_ROOT "/opt/homebrew/opt/mysql-connector-c++")

set(CMAKE_PREFIX_PATH
        ${MYSQL_CONNECTOR_ROOT}
        "/opt/homebrew/opt/openssl"
        "/opt/homebrew/opt/boost"
        ${CMAKE_PREFIX_PATH}
)

set(CMAKE_CXX_STANDARD 17)

# Find required packages
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

# Manually handle MySQL Connector
include_directories(
        ${SPDLOG_INCLUDE_DIRS}
        ${OpenSSL_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        "${MYSQL_CONNECTOR_ROOT}/include"
)

link_directories("${MYSQL_CONNECTOR_ROOT}/lib")
link_directories("/opt/homebrew/Cellar/mysql-connector-c++/9.1.0/lib")


# Add executable
add_executable(YourExecutableName main.cpp
        user_auth.hpp
        chat_server.hpp
        user_thread.hpp
        db_connection.hpp
        db_connection.cpp
        db_connection.cpp
        user_auth.cpp
        user_auth.cpp
        chat_server.cpp
        chat_server.cpp
        chat_server.cpp
        chat_server.cpp
        user_thread.cpp
        user_thread.cpp)

# Link libraries
# 确保正确链接 MySQL X Connector
target_link_libraries(YourExecutableName
        spdlog::spdlog
        fmt::fmt
        OpenSSL::SSL
        OpenSSL::Crypto
        Boost::boost
        #mysqlxcpplib  # 可能需要调整为实际的库名
        mysqlcppconnx
)