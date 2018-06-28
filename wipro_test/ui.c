#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

#define SEED 3

void printIntArray(int A[], int n)
{
    printf("{ ");
    for(int i=0; i< n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("}\n");
}

void getIntArrayFromUser(int A[], int n)
{
    printf("Write %d integers separated by spaces:\n", n);
    for(int i=0; i< n; i++)
    {
        //printf("A[%d] = ", i+1);
        scanf("%d", &A[i]);
    }
}

void generateRandomArray(int A[], int n)
{
    srand(SEED);
    for(int i=0; i<n; i++)
    {
        A[i] = rand()%20;
    }
}

