#include <vector>
#include <random>
#include <cmath>
#include <iostream>

#include "utils.h"
#include "peakFinding1D.h"

std::vector<int> generateRandIntVector(int size)
{
    std::vector<int> randVect(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ditrib(0,10);

    for(auto& elem: randVect)
    {
        elem = ditrib(gen);
    }
    
    return randVect;
}

int main()
{
    println("Testing Peak finding at 1D ...");

    for(std::size_t i=0; i<=6; i++)
    {
        auto vectorSize = std::pow(10, i);
        auto randVect = generateRandIntVector(vectorSize);

        std::cout   << "peak index = " << peakFindLinearSearch(randVect)
                    << " of vector of size = " << vectorSize 
                    << std::endl;

    }
    return 0;
}