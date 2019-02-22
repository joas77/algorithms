#ifndef ARITMETIC_H
#define ARITMETIC_H

#include <stdlib.h>
#include <stdint.h>
#include "vector.h"

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

typedef enum error{
    OK = 0,
    INVALID_STR_REPR = 1
    
}ErrorCode;

typedef struct _stBigNum
{
    uint8_t *number;
    size_t digitNum;
    char * strRepresentation;
}stBigNum;

ErrorCode aritBigNumFromStr(stBigNum *num, char * repr);

stBigNum* aritBigNumInit(size_t digitNum);
stBigNum * aritSum(stBigNum * x, stBigNum * y);


#endif /*ARITMETIC_H*/
