#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace utils { // Or a separate 'utils' namespace
std::vector<std::string> split(const std::string &text, char delimiter);
std::vector<std::string> split(const std::string &text,
                               const std::string &delimiter);
} // namespace utils

namespace logs {
void log(const std::string message);
void exitWithError(const std::string errorMessage);
} // namespace logs
