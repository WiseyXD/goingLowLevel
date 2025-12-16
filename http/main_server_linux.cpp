#include "./utils/route_handlers.hpp"
#include "core/http_tcpServer.hpp"
#include "core/router.hpp"

struct parsedRequest;

int main() {
  using namespace http;

  Router router;
  TcpServer server = TcpServer("0.0.0.0", 8080, router);

  router.get("/", handleGet);
  router.post("/", handlePost);

  server.startListen();

  while (true) {
    server.acceptConnection();
    server.readingRequest();
    server.sendingResponse();
  }

  return 0;
}
