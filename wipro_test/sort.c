#include <stdio.h>
#include "sort.h"

void insertion_sort(int A[], int n)
{
    for(int j = 1; j<n; j++)
    {
        int key = A[j];
        // insert A[j] into sorted sequence A[0..j-1]
        int i = j -1;
        while( i>=0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

/*
 * Prints how many times each element is repeated along 
 * the array, printFrequency assumes A[] is a sorted array
 * */
void printFrequency(int A[], int n)
{
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i] == A[i-1])
        {
            count++;
        }
        else
        {
            printf("Frequency of %d = %d\n", A[i-1], count);
            count = 1;
        }
    }
    printf("Frequency of %d = %d\n", A[n-1], count);

}
