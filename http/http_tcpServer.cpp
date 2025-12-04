#include "http_tcpServer.hpp"

namespace http {

TcpServer::TcpServer(std::string ip_address, int port)
    : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket() {
  startServer();
}

TcpServer::~TcpServer() { closeServer(); }

int TcpServer::startServer() {
  int m_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket < 0) {
    std::cout << "Error occured while creating the socket \n";
    return 1;
  }
  return 0;
}

void TcpServer::closeServer() {
  close(m_socket);
  close(m_new_socket);
  exit(0);
}

} // namespace http
