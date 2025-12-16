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

struct parsedRequest parseRequest(std ::string rawRequest);
