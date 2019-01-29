#ifndef ARITMETIC_H
#define ARITMETIC_H

#include <stdint.h>

typedef struct _stBigNum
{
    uint8_t *number;
    size_t digitNum;
    char * strRepresentation;
}stBigNum;

stBigNum* aritBigNumInit(size_t digitNum);
stBigNum * aritSum(stBigNum * x, stBigNum * y);


#endif /*ARITMETIC_H*/
