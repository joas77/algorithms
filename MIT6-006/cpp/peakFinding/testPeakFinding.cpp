#include <vector>
#include <random>

#include "utils.h"

std::vector<int> generateRandIntVector(int size)
{
    std::vector<int> randVect(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ditrib(0,255);

    for(auto& elem: randVect)
    {
        elem = ditrib(gen);
    }
    
    return randVect;
}

int main()
{
    println("Testing compiling utils...");
    println("Testing generation of empty random vector...");
    auto v = generateRandIntVector(10);
    printVector(v);
    return 0;
}