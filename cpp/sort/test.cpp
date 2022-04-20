#include <iostream>
#include <list>
#include "quickSort.h"
#include "utils.h"

int main()
{
    auto initList = std::initializer_list<int>{3,8,2,5,1,4,7,6};
    auto v = std::vector<int>{initList};
    auto w = v;
    std::cout << "Testing partition with std::vector, pivot = first element ("
        << v.at(0) << ")" << std::endl;
    printVector(v);
    partition(v.begin(), v.end());
    printVector(v);
    std::cout << "****************************" << std::endl;

    std::cout << "Testing quicksort with std::vector" <<std::endl;
    quicksort(v.begin(), v.end());
    printVector(v);
    std::cout << "****************************" << std::endl;

    auto l  = std::list<int>{initList};
    std::cout << "Testing partition with std::list, pivot = first element ("
        << *l.begin() << ")" << std::endl;
    printIterable(l.begin(), l.end());
    partition(l.begin(), l.end());
    printIterable(l.begin(), l.end());
    std::cout << "****************************" << std::endl;

    std::cout << "Testing quicksort with std::list" <<std::endl;
    std::cout << "before sort..." << std::endl;
    printIterable(w.begin(), w.end());
    quicksort(w.begin(), w.end());
    std::cout << "after sort..." << std::endl;
    printIterable(w.begin(), w.end());
    std::cout << "****************************" << std::endl;
    
    return 0;
}