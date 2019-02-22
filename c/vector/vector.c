#include "vector.h"

#define DEFAULT_CAPACITY 2

void uint8Vector_init(uint8Vector * vector)
{
    vector->size = 0;
    vector->capacity = DEFAULT_CAPACITY;
    vector->data = (uint8_t*) malloc(DEFAULT_CAPACITY * sizeof(uint8_t));
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