#include "vector.h"
#include <stdio.h>

void printVector(uint8Vector * vector);

int main()
{
    uint8Vector vector;

    uint8Vector_init(&vector);

    for(size_t i = 0; i < 10; i++)
    {
        uint8Vector_push_back(&vector, i);
        printVector(&vector);
    }


    return 0;
}

void printVector(uint8Vector * vector)
{
    for (size_t i = 0; i< vector->size; i++)
    {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}