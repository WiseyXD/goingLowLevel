#pragma once
#include <iostream>
#include <string>
#include <vector>

struct parsedRequest {
  std::string method;
  std ::string path;
  std::string version;
  std ::string body;
  std::vector<std::pair<std::string, std::string>> headers;
};

namespace utils { // Or a separate 'utils' namespace
std::vector<std::string> split(const std::string &text, char delimiter);
std::vector<std::string> split(const std::string &text,
                               const std::string &delimiter);

struct parsedRequest parseRequest(std ::string rawRequest); // namespace utils
} // namespace utils
namespace logs {
void log(const std::string message);
void exitWithError(const std::string errorMessage);
} // namespace logs
