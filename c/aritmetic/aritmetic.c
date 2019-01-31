#include <string.h>
#include "aritmetic.h"


stBigNum* aritBigNumInit(size_t digitNum)
{
    return NULL;
}

ErrorCode aritBigNumFromStr(stBigNum *num, char * repr)
{
    while(*repr != '\0')
    {
        
    }

    return OK;
}

stBigNum * aritSum(stBigNum * x, stBigNum * y)
{
    stBigNum * pResult = NULL;

    if ( y != NULL && x != NULL) 
    {
        pResult = (stBigNum *) malloc(sizeof(stBigNum));
        uint8_t * pNumber = (uint8_t*) malloc(sizeof(MAX(x->digitNum, y->digitNum) + 1));
        size_t nDigits = x->digitNum > y->digitNum ? x->digitNum : x->digitNum;
        
        uint8_t carry = 0;

        for(size_t i = 0; i < nDigits; i++)
        {
            pNumber[i] = x->number[i] + y->number[i];
           
            uint8_t currentCarry = pNumber[i]/10;
            pNumber[i] = (pNumber[i] % 10) + carry;

            carry = currentCarry;
        }
        
        pResult->number = pNumber;

    }
    
    return result;
}