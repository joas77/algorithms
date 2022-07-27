#pragma once
#include <vector>
#include <iostream>
#include <string_view>

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