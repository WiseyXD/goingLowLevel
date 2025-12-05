#pragma once

#include <arpa/inet.h>  // inet_pton, htons, etc.
#include <netinet/in.h> // defines sockaddr_in and in_addr
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
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

  // private:
  int m_socket;
  std::string m_ip_address;
  int m_port;
  int m_new_socket;
  struct sockaddr_in m_socketAddress;
  socklen_t m_socketAddress_len;
  long m_incomingMessage;
  std::string m_serverMessage;
  ssize_t bytesRead;
  struct sockaddr_in m_clientAddress;
  socklen_t m_clientAddress_len;
  void closeServer();
  int startServer();
  void startListen();
  void acceptConnection();
  void readingRequest();
  void sendingResponse();
};
}; // namespace http
