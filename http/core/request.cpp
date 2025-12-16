#include "request.hpp"
#include "../utils/utility.hpp"

struct parsedRequest parseRequest(std ::string rawRequest) {
  // -------------------------
  // 1. Split request by "\r\n\r\n" -> separates headers from body
  // -------------------------
  bool isJson = false;
  json jsonRequstBody;
  parsedRequest result;

  std::vector<std::string> requestParts = split(rawRequest, "\r\n\r\n");

  const std::string headerSection =
      requestParts.size() > 0 ? requestParts[0] : "";
  std::string bodySection = requestParts.size() > 1 ? requestParts[1] : "";

  // -------------------------
  // 2. Split headerSection by lines
  // -------------------------
  std::vector<std::string> headerLines = split(headerSection, "\n");

  // -------------------------
  // 3. First line → method, path, version
  // -------------------------
  std::string requestLine = headerLines.size() > 0 ? headerLines[0] : "";
  std::vector<std::string> reqParts = split(requestLine, " ");

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

    std::vector<std::string> kv = split(line, ": ");
    if (kv.size() == 2) {
      std::transform(kv[0].begin(), kv[0].end(), kv[0].begin(), ::tolower);
      headers.push_back({kv[0], kv[1]});
    }
  }

  // -------------------------
  // 5. Body (parse JSON if content-type is json)
  // -------------------------
  std::string requestBody = bodySection;

  // for (auto h : headers) {
  //   std::cout << h.first << std::endl;
  //   std::cout << h.second << std::endl;

  //   if (h.first == "content-type" &&
  //       h.second.find("application/json") != std::string::npos) {
  //     isJson = true;
  //     try {
  //       jsonRequstBody = json::parse(requestBody);
  //       std::cout << "JSON BODY PARSED: " << jsonRequstBody.dump(2)
  //                 << std::endl;

  //     } catch (const std::exception &e) {
  //       std::cerr << "JSON parse error: " << e.what() << std::endl;
  //     }
  //   }
  // }

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
  if (isJson) {
    std::cout << "Json true!" << std::endl;
    result.body = jsonRequstBody;
  }

  return result;
};
