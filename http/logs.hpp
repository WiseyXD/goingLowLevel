#pragma once
#include <iostream>
namespace logs {
void log(const std::string message);
void exitWithError(const std::string errorMessage);
} // namespace logs
