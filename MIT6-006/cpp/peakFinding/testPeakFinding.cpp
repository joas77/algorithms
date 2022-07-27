#include <vector>
#include <random>

#include "utils.h"

std::vector<int> generateRandIntVector(int size)
{
    std::vector<int> randVect(size);

    std::random_device r;

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