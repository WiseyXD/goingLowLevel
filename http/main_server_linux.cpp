#include "http_tcpServer.hpp"

int main() {
  using namespace http;
  TcpServer server = TcpServer("0.0.0.0", 8080);

  server.startListen();

  while (true) {
    server.acceptConnection();
    server.readingRequest();
    server.sendingResponse();
  }

  return 0;
}
