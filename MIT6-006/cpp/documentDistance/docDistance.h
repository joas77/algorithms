#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

std::vector<std::string> readFile(std::string_view filePath);
std::unordered_map<std::string, int> countWordFreq(const std::vector<std::string>& words);
