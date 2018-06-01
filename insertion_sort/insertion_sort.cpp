#include <cstddef>
#include "insertion_sort.h"

void insertion_sort(std::vector<int> &A)
{
    for(std::size_t j=1; j < A.size(); j++)
    {
        int key = A[j];
        // insert A[j] into the sorted sequence A[0 .. j]
        std::size_t i = j - 1;
        while(i>=0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}   
