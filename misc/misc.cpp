#include <iostream>
#include <cstddef>
#include "misc.h"

void printIntVector(std::vector<int> &v)
{
    for(std::size_t i=0; i<v.size(); i++)
    {
        std::cout<<v[i]<< " ";
    }
    std::cout<<std::endl;
}

void getIntVectorFromUser(std::vector<int> &v)
{
    int n = 0;
    int elem = 0;
    
    std::cout<< "Please write number of elements: ";
    std::cin>>n;
    std::cout<<std::endl;
    std::cout<< "Please write a list of integers separated by spaces: "; 

    
    for(int i=0; i < n; i++)
    {
        std::cin>>elem;
        v.push_back(elem);
    }
}
