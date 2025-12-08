#include "utilities.hpp"

namespace utils {

std::vector<std::string> split(const std::string &text, char delimiter) {
  std::vector<std::string> parts;
  std::string current;

  for (char c : text) {
    if (c == delimiter) {
      parts.push_back(current);
      current.clear();
    } else {
      current.push_back(c);
    }
  }

  parts.push_back(current);
  return parts;
};

std::vector<std::string> split(const std::string &text,
                               const std::string &delimiter) {
  std::vector<std::string> parts;
  size_t start = 0, end;

  while ((end = text.find(delimiter, start)) != std::string::npos) {
    parts.push_back(text.substr(start, end - start));
    start = end + delimiter.length();
  }

  parts.push_back(text.substr(start));
  return parts;
};

struct parsedRequest parseRequest(std ::string rawRequest) {
  // -------------------------
  // 1. Split request by "\r\n\r\n" -> separates headers from body
  // -------------------------
  parsedRequest result;
  std::vector<std::string> requestParts = utils::split(rawRequest, "\r\n\r\n");

  std::string headerSection = requestParts.size() > 0 ? requestParts[0] : "";
  std::string bodySection = requestParts.size() > 1 ? requestParts[1] : "";

  // -------------------------
  // 2. Split headerSection by lines
  // -------------------------
  std::vector<std::string> headerLines = utils::split(headerSection, '\n');

  // -------------------------
  // 3. First line → method, path, version
  // -------------------------
  std::string requestLine = headerLines.size() > 0 ? headerLines[0] : "";
  std::vector<std::string> reqParts = utils::split(requestLine, ' ');

  std::string method = reqParts.size() > 0 ? reqParts[0] : "";
  std::string path = reqParts.size() > 1 ? reqParts[1] : "";
  std::string httpVersion = reqParts.size() > 2 ? reqParts[2] : "";

  // -------------------------
  // 4. Parse headers into vector of key:value
  // -------------------------
  std::vector<std::pair<std::string, std::string>> headers;

  for (size_t i = 1; i < headerLines.size(); i++) {
    std::string line = headerLines[i];

    // Trim CR if present
    if (!line.empty() && line.back() == '\r')
      line.pop_back();

    if (line.empty())
      continue;

    std::vector<std::string> kv = utils::split(line, ": ");
    if (kv.size() == 2) {
      headers.push_back({kv[0], kv[1]});
    }
  }

  // -------------------------
  // 5. Body (already extracted)
  // -------------------------
  std::string requestBody = bodySection;

  // Debug print (optional)
  // std::cout << "Method: " << method << std::endl;
  // std::cout << "Path: " << path << std::endl;
  // std::cout << "Version: " << httpVersion << std::endl;
  // std::cout << "Body: " << requestBody << std::endl;

  result.method = method;
  result.path = path;
  result.version = httpVersion;
  result.body = requestBody;
  result.headers = headers;
  return result;
};
}; // namespace utils

namespace logs {
void log(const std::string message) { std::cout << message << std::endl; };
void exitWithError(const std::string errorMessage) {
  std::cout << errorMessage << std::endl;
  exit(1);
};
} // namespace logs
