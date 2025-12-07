#cmake_minimum_required(VERSION_4.2.0)
project(HTTP)
add_executable(HTTP main_server_linux.cpp http_tcpServer.cpp http_tcpServer.hpp)
