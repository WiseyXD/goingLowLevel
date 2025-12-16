#include "response.hpp"

std::string buildResponse(const HttpResponse &res) {
  std::ostringstream out;

  out << "HTTP/1.1 " << res.status << " " << res.reason << "\r\n";

  for (const auto &[k, v] : res.headers) {
    out << k << ": " << v << "\r\n";
  }

  out << "Content-Length: " << res.body.size() << "\r\n";
  out << "\r\n";
  out << res.body;

  return out.str();
}
