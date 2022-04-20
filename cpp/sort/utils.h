#include <vector>
#include <iostream>
#include <random>

template <typename T>
std::vector<T> createRandomNumberVector(size_t size, int start, int end)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(start, end);
    
    std::vector<T> v(size, 0);
    for (auto& elem : v)
    {
        elem = distrib(gen);
    }
    
    return v;
}

template <typename T>
void printVector(std::vector<T> v)
{
    std::cout << "[ ";
    for (auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename Iterator>
void printIterable(Iterator start, Iterator end)
{
    std::cout << "[ ";
    while (start != end)
    {
        std::cout << *start << " ";
        ++start;
    }
    std::cout << "]" <<std::endl;
}