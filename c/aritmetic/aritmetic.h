#ifndef ARITMETIC_H
#define ARITMETIC_H

#include <stdint.h>

typedef struct _stBigNum
{
    uint8_t *number;
    uint64_t digitNum;
    char * strRepresentation;
}stBigNum;

stBigNum * aritSum(stBigNum * x, stBigNum * y);


#endif /*ARITMETIC_H*/
