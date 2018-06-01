#include <iostream>
#include "../misc/misc.h"
#include "insertion_sort.h"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, char const *argv[])
{
    std::vector<int> A;

    getIntVectorFromUser(A);

    cout<<"Original array:"<<endl;

    printIntVector(A);
    insertion_sort(A);

    cout<<"Sorted array:"<<endl;

    printIntVector(A);


    return 0;
}

