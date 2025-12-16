#pragma once
#include <functional>
#include <string>
#include <unordered_map>

struct parsedRequest; // forward declaration

class Router {
public:
  using Handler = std::function<std::string(const parsedRequest &)>;
  void post(const std::string &path, Handler handler);
  void get(const std::string &path, Handler handler);
  // void put(std::string &path, Handler handler);
  // void patch(std::string &path, Handler handler);
  // void d_elete(std::string &path, Handler handler);

  std::string handle(const parsedRequest &req);

private:
  std::unordered_map<std::string, Handler> routes;
  std::string makeKey(const std::string &method, const std::string &path) const;
};
