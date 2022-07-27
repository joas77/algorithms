#pragma once

#include <vector>
#include <string>
#include <string_view>

std::vector<std::string> words readFile(std::string_view filePath);