#include "http_tcpServer.hpp"
#include "utilities.cpp"
#include "utilities.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace http {

TcpServer::TcpServer(std::string ip_address, int port)
    : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(),
      m_socketAddress(), m_socketAddress_len(sizeof(m_socketAddress)),
      m_clientAddress(), m_clientAddress_len(sizeof(m_clientAddress)) {
  m_socketAddress.sin_port = htons(port);
  m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
  m_socketAddress.sin_family = AF_INET;
  m_serverMessage = "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: 13\r\n"
                    "\r\n"
                    "Hello, world!";

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
}

void TcpServer::startListen() {
  if (listen(m_socket, 20) < 0) {
    logs::exitWithError("Error occured while listening");
  }

  std::ostringstream ss;
  ss << "\n*** Listening on ADDRESS: " << inet_ntoa(m_socketAddress.sin_addr)
     << " PORT: " << ntohs(m_socketAddress.sin_port) << " ***\n\n";
  logs::log(ss.str());
};

void TcpServer::acceptConnection() {
  m_new_socket =
      accept(m_socket, (sockaddr *)&m_clientAddress, &m_clientAddress_len);

  if (m_new_socket < 0) {
    std::ostringstream ss;
    ss << "Server failed to accept incoming connection from ADDRESS: "
       << inet_ntoa(m_clientAddress.sin_addr)
       << "; PORT: " << ntohs(m_clientAddress.sin_port);
    logs::exitWithError(ss.str());
  }
}

void TcpServer::readingRequest() {
  const int BUFFER_SIZE = 30720;
  char buffer[BUFFER_SIZE] = {0};

  bytesRead = read(m_new_socket, buffer, BUFFER_SIZE);
  if (bytesRead < 0) {
    logs::exitWithError("Error while reading the request stream.");
  }

  std::string rawRequest(buffer);
  parsedRequest parsedRequest = utils::parseRequest(rawRequest);
  for (auto header : parsedRequest.headers) {
    // here we can do routing I guess with the route in the request endpoint
    std::cout << header.first << " : " << header.second << std::endl;
  }
  if (std::holds_alternative<std::string>(parsedRequest.body)) {
    std::cout << "It's a string: " << std::get<std::string>(parsedRequest.body)
              << std::endl;
  } else if (std::holds_alternative<json>(parsedRequest.body)) {
    std::cout << "It's JSON: " << std::get<json>(parsedRequest.body).dump(2)
              << std::endl;
  }
}

void TcpServer::sendingResponse() {
  long bytesSent;
  bytesSent =
      write(m_new_socket, m_serverMessage.c_str(), m_serverMessage.size());
  if (bytesSent == m_serverMessage.size()) {
    logs::log("------ Server Response sent to client ------\n\n");
  } else {
    logs::log("Error sending response to the client");
  }
};

} // namespace http
