#ifndef _VECTOR_H_
#define _VECTOR_H_

/*
C integer vector API implementation
*/
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    uint8_t * data;
    size_t capacity;
    size_t size;
}uint8Vector;

void uint8Vector_init(uint8Vector * vector);
void uint8Vector_delete(uint8Vector * vector);
void uint8Vector_init_sizeof(uint8Vector * vector, size_t size);
void uint8Vector_push_back(uint8Vector * vector, uint8_t data);
uint8_t uint8Vector_at(uint8Vector * vector, size_t index);




#endif /*_VECTOR_H_*/
