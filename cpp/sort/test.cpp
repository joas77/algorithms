#include <iostream>
#include <list>
#include <string>
#include "quickSort.h"
#include "utils.h"

template <typename T>
void runSortTest(std::vector<T>& v, const std::string& msg)
{
    QuickSorter<std::vector<int>::iterator> sorter;
    std::cout << "RUNNING SORT TEST ..." << std::endl;
    std::cout << msg << std::endl;
    std::cout << "Before to sort ..." << std::endl;
    printVector(v);
    sorter.sort(v.begin(), v.end());
    std::cout << "After sort ..." << std::endl;
    printVector(v);
    std::cout << "****************************" << std::endl;
}

// template <typename T>
// void runPartitionTest(std::vector<T>& v, const std::string& msg)
// {
//      std::cout << "RUNNING PARTITION TEST ..." << std::endl;
//     std::cout << msg << std::endl;
//     std::cout << "Before to partition ..." << std::endl;
//     printVector(v);
//     partition(v.begin(), v.end());
//     printVector(v);
//     std::cout << "****************************" << std::endl;
// }

int main()
{
    auto initList = std::initializer_list<int>{3,8,2,5,1,4,7,6, 10, 9};
    auto v = std::vector<int>{initList};
    auto w = v;
    //runPartitionTest(v, "Testing partition with std::vector, pivot = first element");

    runSortTest(v, "Testing quicksort with std::vector");

    auto l  = std::list<int>{initList};
    // std::cout << "Testing partition with std::list, pivot = first element ("
    //     << *l.begin() << ")" << std::endl;
    // printIterable(l.begin(), l.end());
    // partition(l.begin(), l.end());
    // printIterable(l.begin(), l.end());
    // std::cout << "****************************" << std::endl;

    // std::cout << "Testing quicksort with std::list" <<std::endl;
    // std::cout << "before sort..." << std::endl;
    // printIterable(w.begin(), w.end());
    // quicksort(w.begin(), w.end());
    // std::cout << "after sort..." << std::endl;
    // printIterable(w.begin(), w.end());
    // std::cout << "****************************" << std::endl;

    int data;
    std::vector<int> vTest;
    while(std::cin>>data)
    {
        vTest.push_back(data);
    }

    runSortTest(vTest, "Sorting elements from stdin...");
    
    return 0;
}