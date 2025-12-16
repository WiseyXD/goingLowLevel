#cmake_minimum_required(VERSION_4.2.0)
project(HTTP)
add_executable(HTTP main_server_linux.cpp ./core/http_tcpServer.cpp ./core/router.cpp ./core/request.cpp ./utils/logs.cpp ./utils/utility.cpp)
