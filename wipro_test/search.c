#include <stdio.h>
#include "search.h"

int binSearch(int A[], int n, int val)
{
    int leftIndex = 0;
    int rightIndex = n -1;

    while(leftIndex <= rightIndex)
    {
        int i = (leftIndex + rightIndex)/2;

        if(A[i] < val)
        {
            printf("Searching in subArray A[%d..%d]\n", leftIndex, rightIndex);
            leftIndex = i + 1;
        }
        else if(A[i] > val)
        {
            printf("Searching in subArray A[%d..%d]\n", leftIndex, rightIndex);
            rightIndex = i - 1;
        }
        else
        {
            printf("Element %d found in index %d!\n", val, i);
            return i; 
        }
    }
    
    printf("element %d not found\n", val);
    return -1;
}
