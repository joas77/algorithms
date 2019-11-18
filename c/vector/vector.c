#include "vector.h"

#define DEFAULT_CAPACITY 2

void uint8Vector_init(uint8Vector * vector)
{
    vector->size = 0;
    vector->capacity = DEFAULT_CAPACITY;
    vector->data = (uint8_t*) malloc(DEFAULT_CAPACITY * sizeof(uint8_t));
}

/*
* frees data allocated by vector an sets vector to NULL
*/
void uint8Vector_delete(uint8Vector * vector)
{
    free(vector->data);
    free(vector);
    vector = NULL;
}

void uint8Vector_init_sizeof(uint8Vector * vector, size_t size)
{
    uint8Vector_init(vector);

    for(size_t i = 0; i < size; i++)
    {
        uint8Vector_push_back(vector, 0);
    }
    
    //vector->capacity = size;
    vector->size = 0;
}

void uint8Vector_push_back(uint8Vector* vector, uint8_t data)
{
    if (vector->size >= vector->capacity) 
    {
        /* re-allocate more memory, duplicating space */
        size_t newCapacity = ((vector->capacity) << 2);
        vector->data = (uint8_t*) realloc(vector->data, sizeof(uint8_t) * newCapacity);
        vector->capacity = newCapacity;
   }
   vector->data[vector->size] = data;
   vector->size++;
}

uint8_t uint8Vector_at(uint8Vector * vector, size_t index)
{
    // TODO assert index < vector->size
    return vector->data[index];
}


/******** dVector functions ************/
void dVector_init(dVector * vector)
{
    vector->size = 0;
    vector->capacity = DEFAULT_CAPACITY;
    vector->data = (double*) malloc(DEFAULT_CAPACITY * sizeof(double));
}

void dVector_push_back(dVector * vector, double data)
{
    if (vector->size >= vector->capacity) 
    {
        /* re-allocate more memory, duplicating space */
        size_t newCapacity = ((vector->capacity) << 2);
        vector->data = (double*) realloc(vector->data, sizeof(double) * newCapacity);
        vector->capacity = newCapacity;
   }
   vector->data[vector->size] = data;
   vector->size++;
}

dVector * create_dVector(double arr[], size_t size)
{
    dVector * pVector = (dVector*) malloc(sizeof(dVector));
    dVector_init(pVector);

    for (size_t i = 0; i < size; i++)
    {
        dVector_push_back(pVector, arr[i]);
    }
    
    return pVector;
}