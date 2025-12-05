#pragma once

#include <arpa/inet.h>  // inet_pton, htons, etc.
#include <netinet/in.h> // defines sockaddr_in and in_addr
#include <string>
#include <sys/socket.h>
#include <unistd.h>

namespace http {

// struct sockaddr_in {
//   short sin_family;        // e.g. AF_INET
//   unsigned short sin_port; // e.g. htons(8080)
//   struct in_addr sin_addr; // see struct in_addr, below
//   char sin_zero[8];        // zero this if you want to
// };
// struct in_addr {
//   unsigned long s_addr;
// };

class TcpServer {
public:
  TcpServer(std::string ip_address, int port);
  ~TcpServer();

private:
  int m_socket;
  std::string m_ip_address;
  int m_port;
  int m_new_socket;
  struct sockaddr_in m_socketAddress;
  int m_socketAddress_len;
  void closeServer();
  int startServer();
};
}; // namespace http
