#include "http_tcpServer.hpp"
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sys/socket.h>

namespace logs {
void log(const std::string message) { std::cout << message << std::endl; };
void exitWithError(const std::string errorMessage) {
  std::cout << errorMessage << std::endl;
  exit(1);
};
} // namespace logs

namespace http {

TcpServer::TcpServer(std::string ip_address, int port)
    : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(),
      m_socketAddress(), m_socketAddress_len(sizeof(m_socketAddress)) {
  m_socketAddress.sin_port = port;
  m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
  m_socketAddress.sin_family = AF_INET;
  startServer();
}

TcpServer::~TcpServer() { closeServer(); }

int TcpServer::startServer() {
  m_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket < 0) {
    logs::exitWithError("Cannot create a socket at this moment.");
    return 1;
  }
  if (bind(m_socket, (sockaddr *)&m_socketAddress, m_socketAddress_len) < 0) {

    logs::exitWithError("Binding error.");
    return 1;
  }
  logs::log("Created a TCP socket successfully");
  return 0;
}

void TcpServer::closeServer() {
  close(m_socket);
  close(m_new_socket);
  logs::log("Cleanup done, all the sockets are closed.");
  exit(0);
}

} // namespace http
