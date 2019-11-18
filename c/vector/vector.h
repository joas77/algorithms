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

typedef struct
{
    double * data;
    size_t capacity;
    size_t size;
}dVector;


void dVector_init(dVector * vector);
void dVector_delete(dVector * vector);
void dVector_init_sizeof(dVector * vector, size_t size);
void dVector_push_back(dVector * vector, double data);
double dVector_at(dVector * vector, size_t index);

dVector * create_dVector(double arr[], size_t size);

dVector * sum_dVector(dVector * x, dVector * y);
dVector * sub_dVector(dVector * x, dVector * y);
dVector * scalar_mult_dVector(dVector * x, double k);

#endif /*_VECTOR_H_*/
