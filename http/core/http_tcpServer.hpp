#pragma once

#include "response.hpp"
#include <arpa/inet.h>  // inet_pton, htons, etc.
#include <netinet/in.h> // defines sockaddr_in and in_addr
#include <string>
#include <unistd.h>

class Router;

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

struct requestBody {
  std::string method;
  std::string host;
};

class TcpServer {
public:
  TcpServer(std::string ip_address, int port, Router &router);
  ~TcpServer();
  void closeServer();
  int startServer();
  void startListen();
  void acceptConnection();
  void readingRequest();
  void sendingResponse();

private:
  int m_socket;
  std::string m_ip_address;
  int m_port;
  int m_new_socket;
  struct sockaddr_in m_socketAddress;
  socklen_t m_socketAddress_len;
  HttpResponse m_raw_response;
  std ::string m_serverMessage;
  struct requestBody m_requestMessage;
  ssize_t bytesRead;
  struct sockaddr_in m_clientAddress;
  socklen_t m_clientAddress_len;
  Router &m_router;
};
}; // namespace http
