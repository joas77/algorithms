#include <string.h>
#include "aritmetic.h"


stBigNum* aritBigNumNew(size_t digitCount)
{
    stBigNum * num = (stBigNum*) malloc(sizeof(stBigNum));
    num->digitCount = digitCount;
    uint8Vector_init_sizeof(&num->number, digitCount);
    return num;
}

/*
* num shall be an empty number
*/
ErrorCode aritBigNumFromStr(stBigNum *num, const char * str)
{   
    size_t strLen = strlen(str);

    for(int i = strLen-1; i>= 0; i--)
    {
        uint8_t digit = (uint8_t) (str[i] - '0');
        if (digit > 9 ) 
        {
            return INVALID_STR_REPR;
        }
        uint8Vector_push_back(&num->number, digit);
        num->digitCount ++;
    }

    return OK;
}

char * aritBigNumToString(stBigNum * num)
{
    if(num->digitCount == 0)
    {
        return "NaN";
    }
    
    char * str = (char *) malloc((num->digitCount +1) * sizeof(char));
    char * str_it = str;

    str[num->digitCount] = '\0';
    for(int i = num->digitCount - 1; i>=0; i--)
    {
        *str_it = num->number.data[i] + '0';
        str_it++;
    }
    
    return str;
}

stBigNum * aritSum(stBigNum * x, stBigNum * y)
{
    stBigNum * pResult = NULL;

    // if ( y != NULL && x != NULL) 
    // {
    //     pResult = (stBigNum *) malloc(sizeof(stBigNum));
    //     uint8_t * pNumber = (uint8_t*) malloc(sizeof(MAX(x->digitNum, y->digitNum) + 1));
    //     size_t nDigits = x->digitNum > y->digitNum ? x->digitNum : x->digitNum;
        
    //     uint8_t carry = 0;

    //     for(size_t i = 0; i < nDigits; i++)
    //     {
    //         pNumber[i] = x->number[i] + y->number[i];
           
    //         uint8_t currentCarry = pNumber[i]/10;
    //         pNumber[i] = (pNumber[i] % 10) + carry;

    //         carry = currentCarry;
    //     }
        
    //     pResult->number = pNumber;

    // }
    
    return pResult;
}