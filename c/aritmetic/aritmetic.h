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
    uint8Vector number;
    size_t digitCount;
}stBigNum;

ErrorCode aritBigNumFromStr(stBigNum *num, const char * str);
char * aritBigNumToString(stBigNum * num);

stBigNum * aritBigNumNew(size_t digitCount);
stBigNum * aritSum(stBigNum * x, stBigNum * y);


#endif /*ARITMETIC_H*/
