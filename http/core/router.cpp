#include "router.hpp"
#include "request.hpp"

void Router::post(const std::string &path, Handler handler) {
  routes[makeKey("POST", path)] = handler;
};

void Router::get(const std::string &path, Handler handler) {

  routes[makeKey("GET", path)] = handler;
};

void Router::patch(const std::string &path, Handler handler) {

  routes[makeKey("PATCH", path)] = handler;
};

void Router::put(const std::string &path, Handler handler) {

  routes[makeKey("PUT", path)] = handler;
};

void Router::d_elete(const std::string &path, Handler handler) {

  routes[makeKey("DELETE", path)] = handler;
};

std::string Router::handle(const parsedRequest &req) {
  std::string key = makeKey(req.method, req.path);

  auto it = routes.find(key);
  if (it == routes.end()) {
    return "HTTP/1.1 404 Not Found\r\n\r\nRoute not found";
  }

  return it->second(req);
};

std::string Router::makeKey(const std::string &method,
                            const std::string &path) const {
  std::string key = method + ":" + path;
  return key;
};
