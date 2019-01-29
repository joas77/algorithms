#include <stdlib.h>
#include "aritmetic.h"


stBigNum * aritSum(stBigNum * x, stBigNum * y)
{
    stBigNum * result = NULL;

    if ( y != NULL && x != NULL) 
    {
        size_t nDigits = x->digitNum > y->digitNum ? : x->digitNum;
        uint8_t carry = 0;
        for(size_t i = 0; i < nDigits; i++)
        {
            // TODO
        }
        
    }
    
    return result;
}