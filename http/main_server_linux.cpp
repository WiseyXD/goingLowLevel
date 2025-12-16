#include "core/http_tcpServer.hpp"
#include "core/request.hpp"
#include "core/router.hpp"

struct parsedRequest;

std::string handleGet(const parsedRequest &req) {
  return "GET request from " + req.path;
};

std::string handlePost(const parsedRequest &req) {
  return

      "POST request from " + req.path;
};

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
