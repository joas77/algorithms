#include <stdio.h>
#include "sort.h"
#include "ui.h"
#include "search.h"

#define SIZE 20

int main()
{
    int A[SIZE];

    //getIntArrayFromUser(A, SIZE);
    generateRandomArray(A, SIZE);
    printf("unsorted array:\n");
    printIntArray(A, SIZE);
    printf("\n");

    insertion_sort(A, SIZE);
    printf("sorted array:\n");
    printIntArray(A, SIZE); 
    printf("\n");
    
    printFrequency(A, SIZE);

    int search1 = 1;
    int search2 = 10;
    printf("\n");
    printf("Searching %d...\n", search1);
    binSearch(A, SIZE, search1);

    printf("\n");
    printf("Searching %d...\n", search2);
    binSearch(A, SIZE, search2);
    
    return 0;
}
