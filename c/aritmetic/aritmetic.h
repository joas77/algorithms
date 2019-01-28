#ifndef ARITMETIC_H
#define ARITMETIC_H

#include <stdint.h>

typedef struct
{
    uint8_t **number;
    uint64_t digitNum;
    char * strRepresentation;
}stBigNum;

int arit_sum(stBigNum * x, stBigNum * y, stBigNum result);


#endif /*ARITMETIC_H*/
