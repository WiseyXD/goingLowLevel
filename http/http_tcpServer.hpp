#pragma once

#include <string>
#include <sys/socket.h>
#include <unistd.h>

namespace http {

class TcpServer {
public:
  TcpServer(std::string ip_address, int port);
  ~TcpServer();

private:
  int m_socket;
  std::string m_ip_address;
  int m_port;
  int m_new_socket;

  void closeServer();
  int startServer();
};
}; // namespace http
