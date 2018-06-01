#include <iostream>
#include "misc.h"

int main()
{
    std::vector<int> inVector;

    getIntVectorFromUser(inVector);

    std::cout<< "input vector"<<std::endl;
    printIntVector(inVector);

    return 0;
}
