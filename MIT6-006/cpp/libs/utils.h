#pragma once
#include <vector>
#include <iostream>
#include <string_view>
#include <unordered_map>

template <typename T>
void printVector(std::vector<T> v)
{
    std::cout << "[ ";
    for(const auto& elem : v)
        std::cout << elem << ", ";

    std::cout << "]" << std::endl;
}

void println(std::string_view msg)
{
    std::cout << msg << std::endl;
}

template <typename Key, typename Value>
void printDict(const std::unordered_map<Key, Value>& dict)
{
    std::cout << "{" << std::endl;
    for(const auto[key, val] : dict)
    {
        std::cout << key << " : " << val << std::endl;
    }
    std::cout << "}" << std::endl;
}
