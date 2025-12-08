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

}; // namespace utils

namespace logs {
void log(const std::string message) { std::cout << message << std::endl; };
void exitWithError(const std::string errorMessage) {
  std::cout << errorMessage << std::endl;
  exit(1);
};
} // namespace logs
