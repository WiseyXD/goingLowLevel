#include "logs.hpp"

namespace logs {
void log(const std::string message) { std::cout << message << std::endl; };
void exitWithError(const std::string errorMessage) {
  std::cout << errorMessage << std::endl;
  exit(1);
};
} // namespace logs
