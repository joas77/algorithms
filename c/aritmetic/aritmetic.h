#ifndef ARITMETIC_H
#define ARITMETIC_H

#include <stdlib.h>
#include <stdint.h>
#include "vector.h"

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )
#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

typedef enum error{
    OK = 0,
    INVALID_STR_REPR = 1,
    INVALID_NUMBER = 2
    
}ErrorCode;

typedef struct _stBigNum
{
    uint8Vector number;
    size_t digitCount;
}stBigNum;

ErrorCode aritBigNumFromStr(stBigNum *num, const char * str);
void aritBigNumDelete(stBigNum * num);
char * aritBigNumToString(stBigNum * num);

stBigNum * aritBigNumNew(size_t digitCount);
ErrorCode aritSum(stBigNum * result, stBigNum * x, stBigNum * y);


#endif /*ARITMETIC_H*/
