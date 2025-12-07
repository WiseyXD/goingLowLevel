#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

// vector<string> split(string &message, char delimiter) {
//   vector<string> parts;
//   std::string current;
//   for (char c : message) {
//     if (c == delimiter) {
//       parts.push_back(current);
//       current.clear();
//     } else {
//       current.push_back(c);
//     }
//   }
//   return parts;
// }

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
}

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
}

int main() {
  vector<string> v1;
  string m_serverMessage = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/plain\r\n"
                           "Content-Length: 13\r\n"
                           "\r\n"
                           "Hello, world!";
  v1 = split(m_serverMessage, "\r\n");
  cout << v1[0];

  return 0;
}
