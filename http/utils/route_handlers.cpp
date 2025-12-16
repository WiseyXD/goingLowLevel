#include "route_handlers.hpp"

std::string handleGet(const parsedRequest &req) {
  return "GET request from " + req.path;
};

std::string handlePost(const parsedRequest &req) {
  return "POST request from " + req.path;
};
