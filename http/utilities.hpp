#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <variant>
#include <vector>

using json = nlohmann::json;

struct parsedRequest {
  std::string method;
  std ::string path;
  std::string version;
  std::variant<std ::string, json> body;
  std::vector<std::pair<std::string, std::string>> headers;
};

namespace utils { // Or a separate 'utils' namespace
std::vector<std::string> split(const std::string &text, char delimiter);
std::vector<std::string> split(const std::string &text,
                               const std::string &delimiter);
struct parsedRequest parseRequest(std ::string rawRequest); // namespace utils
void routing(std::string path, void (*callback)());
void test();

} // namespace utils
